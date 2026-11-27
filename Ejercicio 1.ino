using System;

class Program
{
    static void Main()
    {
        // Ejemplo de uso con una matriz de enteros (2x3)
        int[,] matriz = {
            { 1, 2, 3 },
            { 4, 5, 6 }
        };

        int resultado = SumarElementosMatriz(matriz);
        Console.WriteLine($"La suma de los elementos de la matriz es: {resultado}");
    }

    // Método para el Ejercicio 1
    static int SumarElementosMatriz(int[,] matriz)
    {
        int suma = 0;

        // Recorremos las filas (dimensión 0)
        for (int i = 0; i < matriz.GetLength(0); i++)
        {
            // Recorremos las columnas (dimensión 1)
            for (int j = 0; j < matriz.GetLength(1); j++)
            {
                suma += matriz[i, j];
            }
        }

        return suma;
    }
}
