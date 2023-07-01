# Why you made this code?
By reading the pages 51-59, I searched for a keylogger malware sample in MalwareBaazar. As I'm in the basic of basic, I started to read some functions this malware imports and selected the mosts "atractives", so I've choosed: `GetStdHandle`, `CreateFileA`, `ReadConsole` and `WriteFile`. 

## Functions
#### GetStdHandle
_"Retrieves a handle to the specified standard device (standard input, standard output, or standard error)"_. We will use this function to indicate the standard device(keyboard) we will obtain data, so this handle will be the standard input device.

#### CreateFileA
_"Creates or opens a file or I/O device."_ . Easy, this will basically create a file, note that it receive a few values, the below table specifies what are these values.
| Parameters | Value | Description |
| -- | -- | -- |
| FileName | file | The filename the function will create. |
| DesiredAccess | GENERIC_READ \| GENERIC_WIRTE | Access permission for the file, in this case, read and write.
| ShareMode | 0 | This means that this file can't be opened or shared, again, until the handle closes(CloseHandle(handle))
| SecurityAttributes | NULL | This parameter is used to set permission of inherit, as it is set to NULL, this handle(file_h) cannot be inherited. |
| CreationDisposition | CREATE_ALWAYS | "An action to take on a file", in this case, CREATE_ALWAYS means that, even if the file exists, a new file will be created.|
| FlagsAndAttributes | FILE_ATTRIBUTE_NORMAL | This file we will create will not have special attributes, like hidden or read-only. |
| TemplateFile | NULL | Basically this parameter will set a template of permissions, attributes and other details. In this case, we won't use any model/template.

#### ReadConsole
_"Reads character input from the console input buffer and removes it from the buffer"._ - This function will be responsible for read from the Console Input and store in buffer. Again, the table below explain the values and the parameters:
| Parameters | Value | Description |
| -- | -- | -- |
| ConsoleInput | hand | A handle from which it will be reading, in this case, our handle is the Keyboard. |
| Buffer | buf | This is where the data that was readed will be saved. |
| NumberOfCharsToRead | sizeof(buf) | Simply, this will be the number of chars it will read, in this case will be the size of the `buf` variable. |
| NumberOfCharsRead | &readed | This will be the value of chars that are actually readed. |
| InputControl | NULL | This parameter would set a key that, once pressed, the read function would stop. |

#### WriteFile
_"Writes data to the specified file or input/output (I/O) device."_- Just like the CreateFile function, this one is also easy to understand as we write data to a file, following the same model:
| Parameters | Value | Description |
| -- | -- | -- |
| File | file_h | This is where the program will write the data.
| Buffer | buf | The data that will be written.
| NumberOfBytesToWrite | readed | The number of bytes that will be written. In this case, the value `readed` will contain the number of bytes readed by the ReadConsole function. 
| NumberOfBytesWritten | NULL | A pointer to a variable that stores the number of chars written.
| Overlapped | NULL | Responsible for Assynchronous operations, explanations is a little complex but it's in Microsoft Documentation. |

## Executing
The execution is simples, by run the program it will open the console(cmd), you can type and when you finished it will write to the file, `file.txt`.

