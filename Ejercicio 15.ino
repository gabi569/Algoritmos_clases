using System;

class Program
{
    static void Main()
    {
        // Definición de dos matrices de ejemplo (2x3)
        double[,] matrizA = {
            { 1.5, 2.0, 3.5 },
            { 4.0, 5.5, 6.0 }
        };

        double[,] matrizB = {
            { 0.5, 1.0, 2.5 },
            { 3.0, 1.5, 4.0 }
        };

        try
        {
            double[,] resultado = SumarMatrices(matrizA, matrizB);

            Console.WriteLine("Matriz resultante:");
            ImprimirMatriz(resultado);
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
    static double[,] SumarMatrices(double[,] matriz1, double[,] matriz2)
    {
        int filas1 = matriz1.GetLength(0);
        int columnas1 = matriz1.GetLength(1);
        int filas2 = matriz2.GetLength(0);
        int columnas2 = matriz2.GetLength(1);

        // Validar que ambas matrices tengan exactamente las mismas dimensiones
        if (filas1 != filas2 || columnas1 != columnas2)
        {
            throw new ArgumentException("Las matrices deben tener las mismas dimensiones para poder sumarse.");
        }

        double[,] suma = new double[filas1, columnas1];

        for (int i = 0; i < filas1; i++)
        {
            for (int j = 0; j < columnas1; j++)
            {
                suma[i, j] = matriz1[i, j] + matriz2[i, j];
            }
        }

        return suma;
    }

    // Método auxiliar para mostrar la matriz en consola
    static void ImprimirMatriz(double[,] matriz)
    {
        for (int i = 0; i < matriz.GetLength(0); i++)
        {
            for (int j = 0; j < matriz.GetLength(1); j++)
            {
                Console.Write(matriz[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
