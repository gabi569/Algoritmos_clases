using System;

class Program
{
    static int EliminarDuplicado(int[] nums)
    {
        if (nums.Length == 0)
            return 0;

        int Escritura = 1;

        for (int Lectura = 1; Lectura < nums.Length; Lectura++)
        {
            if (nums[Lectura] != nums[Lectura - 1])
            {
                nums[Escritura] = nums[Lectura];
                Escritura++;
            }
        }

        return Escritura;
    }

    static void Main()
    {
        int[] nums = { 1, 1, 2, 2, 3, 4, 4, 5 };

        int NuevaLongitud = EliminarDuplicado(nums);

        Console.WriteLine("Nueva Longitud: " + NuevaLongitud);
        
        for (int i = 0; i < NuevaLongitud; i++)
        {
            Console.Write(nums[i] + " ");
        }
    }
}