
#include "flash.h"
#include "fatfs.h"

#if defined (MCU_SERIES_F7)
#define FLASH_FLAG_PGSERR   (FLASH_FLAG_ERSERR)
#endif

extern void __fatal_error();




void flash_write(uint8_t *wtext)
{
	
	static FATFS mynewdiskFatFs;
		static FIL MyFile;
		static char mynewdiskPath[4]; 
	  uint32_t wbytes; /* File write counts */  
		if(FATFS_LinkDriver(&USER_Driver, mynewdiskPath) == 0)  {    
			if(f_mount(&mynewdiskFatFs, (TCHAR const*)mynewdiskPath, 0) == FR_OK){      
				if(f_open(&MyFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) == FR_OK){        
					if(f_write(&MyFile, wtext, sizeof(wtext), (uint32_t *)&wbytes) == FR_OK){          
		         f_close(&MyFile);        
		      }      
		    }    
		  }  
		}  
		FATFS_UnLinkDriver(mynewdiskPath);
}
void flash_read(uint8_t *rtext)
{

	static FATFS mynewdiskFatFs;
		static FIL MyFile;
		static char mynewdiskPath[4]; 
	  uint32_t wbytes; /* File write counts */  
		if(FATFS_LinkDriver(&USER_Driver, mynewdiskPath) == 0)  {    
			if(f_mount(&mynewdiskFatFs, (TCHAR const*)mynewdiskPath, 0) == FR_OK){      
				if(f_open(&MyFile, "STM32.TXT",FA_READ) == FR_OK){        
					if(f_read(&MyFile, rtext, sizeof(rtext), (uint32_t *)&wbytes) == FR_OK){          
		         f_close(&MyFile);        
		      }      
		    }    
		  }  
		}  
		FATFS_UnLinkDriver(mynewdiskPath);
}

