# Pet-database 
>The actual database consists of three tables:
>
>- The main table of modules ("MODULES") consists of:
>  - Module ID (int);
>  - Module name (char[30]);
>  - Number of the memory level where the module is located (int);
>  - Number of the cell where the module is located on this level (int);
>  - Deletion flag (int). 
>- Table of levels ("LEVELS") consists of:
>  - Number of memory level (int);
>  - The number of cells on the level (int);
>  - Protection flag (int). 
>- Table of status change events ("STATUS_EVENTS") consists of:
>  - Event ID (int);
>  - Module ID (int);
>  - New module status (int);
>  - Status change date (char[10 + 1] in the "dd.mm.yyyy`\0`" format);
>  - Status change time (char[8 + 1] in the "hh:mm:ss`\0`" format).

## Master DB.

*** implementation of SELECT, INSERT, UPDATE, DELETE for fixed tables
