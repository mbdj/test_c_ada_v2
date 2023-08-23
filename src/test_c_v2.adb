pragma Ada_2012;

--  with Ada.Real_Time; use Ada.Real_Time;

package body Test_C_V2 is

   ---------------
   -- Main_Loop --
   ---------------

   procedure Main_Loop is
      use Interfaces;

      --  Period       : constant Time_Span := Milliseconds (1000);
      --  Next_Release : Time := Clock;

      N : Interfaces.Unsigned_32 := 1;
      Msg : constant String := "ADA";

   begin
      Tft_Init;
      Tft_Println (Msg'Address);

      loop
         Blink (N);
         N := N + 1;

         Delai (1000);

         Tft_Println (Msg'Address);

         --  Next_Release := Next_Release + Period;
         --  delay until Next_Release;
      end loop;

   end Main_Loop;

end Test_C_V2;
