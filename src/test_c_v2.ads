with Interfaces;
with System;

package Test_C_V2 is

   -- API exported to the C code --

   procedure Main_Loop;
   pragma Export (C, Main_Loop, "mainLoop");

   -- API imported from C code --

   procedure Blink (N : Interfaces.Unsigned_32);
   pragma Import (C, Blink, "blink");

   procedure Delai (Ms : Interfaces.Unsigned_32);
   pragma Import (C, Delai, "delai");

   procedure Tft_Init;
   pragma Import (C, Tft_Init, "tftInit");

   procedure Tft_Println (String : System.Address);
   pragma Import (C, Tft_Println, "tftPrintln");

end Test_C_V2;
