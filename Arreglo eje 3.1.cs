using System;

class Program
{
    static void Main()
    {
        int[] Arreglo = { 1, 2, 3, 4, 5, 6, 7 };
        int rotaciones = 2;

        rotaciones = rotaciones % Arreglo.Length;

        int[] Resultado = new int[Arreglo.Length];

        for (int i = 0; i < Arreglo.Length; i++)
        {
            Resultado[(i + rotaciones) % Arreglo.Length] = Arreglo[i];
        }

        foreach(int num in Resultado)
        {
            Console.Write(num + " ");
        }
    }
}