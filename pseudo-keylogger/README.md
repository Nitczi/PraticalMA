# Why you made this code?
By reading the pages 51-59, I searched for a keylogger malware sample in MalwareBaazar. As i'm in the basic of basic, i started to read some functions this malware imports and selected the mosts "atractives", so i've choosed: GetStdHandle, CreateFileA, ReadConsole and WriteFile. 

## Functions
#### GetStdHandle
_"Retrieves a handle to the specified standard device (standard input, standard output, or standard error)"_. We will use this function to indicate the standard device(keyboard) we will obtain data, so this handle will be the standard input device.

#### CreateFileA
_"Creates or opens a file or I/O device."_ . Easy, this will basically create a file, note that it receive a few values, the below table specifies what are these values.
| Parameters | Description |
| -- | -- |
| file | The filename it will create |
| GENERIC_READ \| GENERIC_WIRTE | Access permission for the file, in this case, read and write
| 0 (ShareMode)| this means that this file can't be opened or shared again until the handle closes(CloseHandle(handle))
| NULL () | 
