using System;

class Program
{
    static bool EsPrimo(int n)
    {
        if (n < 2)
            return false;

        for (int i = 2; i <= Math.Sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    
    static void Main()
    {
        Random r = new Random();

        int[] numeros = new int[15];
        int CantidadPrimos = 0;

        for (int i = 0; i < numeros.Length; i++)
        {
            numeros[i] = r.Next(1, 51);

            if (EsPrimo(numeros[i]))
                CantidadPrimos++;
        }

        int[] primos = new int[CantidadPrimos];

        int indice = 0;

        for (int i = 0; i < numeros.Length; i++)
        {
            if (EsPrimo(numeros[i]))
            {
                primos[indice] = numeros[i];
                indice++;
            }
        }


        Console.WriteLine("Numeros originales: ");
        foreach (int num in numeros)
            Console.Write(num + " ");

        Console.WriteLine("\nPrimos: ");

        foreach (int num in primos)
            Console.Write(num + " ");
    }
}