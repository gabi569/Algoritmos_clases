using System;

public class OperacionesMatrices
{
    public static double[,] MultiplicarMatrices(double[,] matrizA, double[,] matrizB)
    {
        // Obtener dimensiones de las matrices
        int filasA = matrizA.GetLength(0);
        int columnasA = matrizA.GetLength(1);
        int filasB = matrizB.GetLength(0);
        int columnasB = matrizB.GetLength(1);

        // Validar que las matrices se puedan multiplicar
        if (columnasA != filasB)
        {
            throw new ArgumentException("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.");
        }

        // Crear la matriz resultante con dimensiones [filasA, columnasB]
        double[,] resultado = new double[filasA, columnasB];

        // Realizar la multiplicación
        for (int i = 0; i < filasA; i++)
        {
            for (int j = 0; j < columnasB; j++)
            {
                double suma = 0;
                for (int k = 0; k < columnasA; k++)
                {
                    suma += matrizA[i, k] * matrizB[k, j];
                }
                resultado[i, j] = suma;
            }
        }

        return resultado;
    }

    // Ejemplo de uso
    public static void Main()
    {
        double[,] a = {
            { 1.0, 2.0, 3.0 },
            { 4.0, 5.0, 6.0 }
        };

        double[,] b = {
            { 7.0, 8.0 },
            { 9.0, 10.0 },
            { 11.0, 12.0 }
        };

        double[,] producto = MultiplicarMatrices(a, b);

        // Imprimir resultado
        for (int i = 0; i < producto.GetLength(0); i++)
        {
            for (int j = 0; j < producto.GetLength(1); j++)
            {
                Console.Write(producto[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
