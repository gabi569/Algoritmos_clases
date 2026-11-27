using System;

class Program
{
    static void Main()
    {
        // Ejemplo de matriz original de 2x3
        double[,] matrizOriginal = {
            { 1.5, 2.0, 3.5 },
            { 4.1, 5.2, 6.8 }
        };

        Console.WriteLine("Matriz Original:");
        ImprimirMatriz(matrizOriginal);

        // Llamada al método para transponer
        double[,] matrizTranspuesta = TransponerMatriz(matrizOriginal);

        Console.WriteLine("\nMatriz Transpuesta:");
        ImprimirMatriz(matrizTranspuesta);
    }

    /// <summary>
    /// Método que recibe una matriz de dobles y devuelve una nueva matriz transpuesta.
    /// </summary>
    static double[,] TransponerMatriz(double[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        // La transpuesta invierte las dimensiones: [columnas, filas]
        double[,] transpuesta = new double[columnas, filas];

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                transpuesta[j, i] = matriz[i, j];
            }
        }

        return transpuesta;
    }

    // Método auxiliar para mostrar el resultado en consola
    static void ImprimirMatriz(double[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Console.Write(matriz[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
