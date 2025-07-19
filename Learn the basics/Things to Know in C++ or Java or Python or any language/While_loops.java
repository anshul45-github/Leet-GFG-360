// https://www.geeksforgeeks.org/problems/while-loop-printtable-java/1

class Geeks {
	 static void printTable (int n) 
	 {
            int multiplier=10;
            while(multiplier>0)
            {
                System.out.print(multiplier * n + " ");
                multiplier--;
            }
       System.out.println();
	 }

}