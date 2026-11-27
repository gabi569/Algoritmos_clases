using System;

class Program
{
    static void Main()
    {
        // Ejemplo de prueba con dos matrices de 2x3
        double[,] matrizA = {
            { 10.5, 20.0, 30.2 },
            { 40.0, 50.8, 60.0 }
        };

        double[,] matrizB = {
            { 5.5, 10.0, 15.2 },
            { 20.0, 25.3, 30.0 }
        };

        try
        {
            double[,] resultado = RestarMatrices(matrizA, matrizB);

            Console.WriteLine("Matriz Resultante (A - B):");
            ImprimirMatriz(resultado);
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
    public static double[,] RestarMatrices(double[,] matrizA, double[,] matrizB)
    {
        // Validar que ninguna matriz sea nula
        if (matrizA == null || matrizB == null)
        {
            throw new ArgumentNullException("Las matrices no pueden ser nulas.");
        }

        int filasA = matrizA.GetLength(0);
        int columnasA = matrizA.GetLength(1);
        int filasB = matrizB.GetLength(0);
        int columnasB = matrizB.GetLength(1);

        // Validar que ambas matrices tengan exactamente las mismas dimensiones
        if (filasA != filasB || columnasA != columnasB)
        {
            throw new ArgumentException("Las matrices deben tener las mismas dimensiones para poder restarse.");
        }

        double[,] matrizResultado = new double[filasA, columnasA];

        // Recorrer filas y columnas para realizar la resta elemento por elemento
        for (int i = 0; i < filasA; i++)
        {
            for (int j = 0; j < columnasA; j++)
            {
                matrizResultado[i, j] = matrizA[i, j] - matrizB[i, j];
            }
        }

        return matrizResultado;
    }
    private static void ImprimirMatriz(double[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Console.Write($"{matriz[i, j]:F2}\t");
            }
            Console.WriteLine();
        }
    }
}
