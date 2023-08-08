# Simple-Driver

### Loading and Running the Driver

Build the driver and copy the entire contents of the Debug directory (`C:\Path\to\FirstDriver\x64\Debug`) to your VM (such as `C:\FirstDriver`).

There are two main methods to load a driver.  The first is using the native `sc.exe` command-line tool.

		sc create FirstDriver type= kernel binPath= C:\FirstDriver\FirstDriver.sys

This will register a Service that you can also read back (notice the type **KERNEL_DRIVER**).
It will also be registered under `HKLM\SYSTEM\CurrentControlSet\Services\FirstDriver`.

You can then start the driver using `sc start`.

		sc start FirstDriver


Another popular tool is the [OSR Driver Loader](https://www.osronline.com/article.cfm%5Earticle=157.htm). It does the same thing as sc but in a nice GUI.

Once the driver has started, you should see the appropriate output in WinDbg
When testing new versions of the driver, it's not necessary to fully delete the associated service.  Simply stop the service, replace the driver files and start the service again.
