using System;

class Program
{
    static void Main()
    {
        int[] numeros = { 12, 5, 30, 8, 45, 2, 18, 25 };

        int mayor = numeros[0];
        int menor = numeros[0];
        int posMayor = 0;
        int posMenor = 0;

        for (int i = 1; i < numeros.Length; i++)
        {
            if (numeros[i] > mayor)
            {
                mayor = numeros[i];
                posMayor = i;
            }
            if (numeros[i] < menor)
            {
                menor = numeros[i];
                posMenor = i;
            }
        }

        Console.WriteLine("Mayor: " + mayor + " indice: " + posMayor);
        Console.WriteLine("Menor: " + menor + " indice: " + posMenor);
    }
}
