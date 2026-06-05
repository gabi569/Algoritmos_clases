using System;

class Program
{
    static void Main()
    {
        int[] numeros = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

        int suma = 0;

        for (int i = 0; i < numeros.Length; i++) 
        {
            suma += numeros[i];
        }

        double promedio = (double)suma / numeros.Length;

        Console.WriteLine("suma: " + suma);

        Console.WriteLine("promedio: " + promedio);
    }
}
