# Why you made this code?
By reading the pages 51-59, I searched for a keylogger malware sample in MalwareBaazar. As i'm in the basic of basic, i started to read some functions this malware imports and selected the mosts "atractives", so i've choosed: GetStdHandle, CreateFileA, ReadConsole and WriteFile. 

## Functions
#### GetStdHandle
_"Retrieves a handle to the specified standard device (standard input, standard output, or standard error)"_. We will use this function to indicate the standard device(keyboard) we will obtain data, so this handle will be the standard input device.

#### CreateFileA
_"Creates or opens a file or I/O device."_ . Easy, this will basically create a file, note that it receive a few values, the below table specifies what are these values.
| Parameters | Value | Description |
| -- | -- | -- |
| FileName | file | The filename it will create. |
| DesiredAccess | GENERIC_READ \| GENERIC_WIRTE | Access permission for the file, in this case, read and write.
| ShareMode | 0 | This means that this file can't be opened or shared, again, until the handle closes(CloseHandle(handle))
| SecurityAttributes | NULL | This parameter is used to set permission of inherit, as it is set to NULL, this handle(file_h) cannot be inherited. |
| CreationDisposition | CREATE_ALWAYS | "An action to take on a file", in this case, CREATE_ALWAYS means that, even if the file exists, a new file will be created.|
| FlagsAndAttributes | FILE_ATTRIBUTE_NORMAL | This file we will create will not have special attributes like, hidden or read-only. |
| TemplateFile | NULL | Basically this parameter will set a template of permissions, attributes and other details. In this case, we won't use any model/template.

#### ReadConsole
_"Reads character input from the console input buffer and removes it from the buffer"._ - This function will be responsibloe for read from the Console Input and store in buffer. Again, the table below explain the values and the parameters:
| Parameters | Value | Description |
| -- | -- | -- |
| ConsoleInput | hand | A handle from where it will be reading from, in this case, our handle is the Keyboard  

