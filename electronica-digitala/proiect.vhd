library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity Proiect_GATE is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : in STD_LOGIC;
           clock : in STD_LOGIC;
           LEDOUT : out STD_LOGIC);
end Proiect_GATE;

architecture Behavioral of Proiect_GATE is
    signal state: std_logic := '0';
    signal input: std_logic_vector(1 downto 0);
begin


    proc: process(clock)
        variable n : integer range 0 to 1000000000;
        variable clockstate : integer range 0 to 10;
    begin
	
	   -- rising edge
	   if clock'event and clock = '1' then
	   
	       -- start clock definitions
	       if n < 100000000 then
	           n := n + 1;
	       else
	           n := 0;
	       end if;
	       
	       if n <= 50000000 then
	           clockstate := 1;
	       else
	           clockstate := 0;
	       end if;
	       -- end clock definitions
	       if clockstate = 1 then
               if A = '0' then
                   -- jk
                   input <= B & C;
                   case input is
                       when "11" =>
                           state <= not state;
                       when "10" =>
                           state <= '1';
                       when "01" =>
                           state <= '0';
                       when others =>
                           null;
                       end case;
               else
                   if B = '0' then
                       -- d
                       state <= C;
                   else
                       -- t
                       state <= not C;          
                   end if;
               end if;
           end if;
	   end if;
    end process;

    LEDOUT <= state;

end Behavioral;
