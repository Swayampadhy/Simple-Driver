# Simple-Driver

### Loading and Running the Driver

Build the driver and copy the entire contents of the Debug directory (`C:\Path\to\FirstDriver\x64\Debug`) to your VM (such as `C:\FirstDriver`).

There are two main methods to load a driver.  The first is using the native `sc.exe` command-line tool.

		sc create FirstDriver type= kernel binPath= C:\FirstDriver\FirstDriver.sys

This will register a Service that you can also read back (notice the type **KERNEL_DRIVER**).
It will also be registered under `HKLM\SYSTEM\CurrentControlSet\Services\FirstDriver`.

You can then start the driver using `sc start`.

		sc start FirstDriver

![image](https://github.com/Swayampadhy/Simple-Driver/assets/37104162/e47a649d-4079-40b0-83af-2f6a844ee91f)
![image](https://github.com/Swayampadhy/Simple-Driver/assets/37104162/54dbed13-cf73-4a66-a8f2-224f426f7e7d)

Now to run the client code - 

		C:\FirstDriver\Driver_Client.exe
![image](https://github.com/Swayampadhy/Simple-Driver/assets/37104162/4c8da03e-3035-4534-bcf5-a228a14b32c3)
![image](https://github.com/Swayampadhy/Simple-Driver/assets/37104162/6f9748e8-a05f-4d0f-afcc-bd7c740af8dc)

Another popular tool is the [OSR Driver Loader](https://www.osronline.com/article.cfm%5Earticle=157.htm). It does the same thing as sc but in a nice GUI.

Once the driver has started, you should see the appropriate output in WinDbg
When testing new versions of the driver, it's not necessary to fully delete the associated service.  Simply stop the service, replace the driver files and start the service again.
