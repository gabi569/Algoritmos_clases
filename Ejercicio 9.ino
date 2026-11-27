using System;

class Program
{
    static void Main()
    {
        // Ejemplo de matriz de enteros (3 filas x 4 columnas)
        int[,] matriz = {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 }
        };

        int indiceFila = 1; // Representa la segunda fila: { 5, 6, 7, 8 }

        try
        {
            int resultado = SumarFila(matriz, indiceFila);
            Console.WriteLine($"La suma de los elementos de la fila {indiceFila} es: {resultado}");
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
    static int SumarFila(int[,] matriz, int fila)
    {
        // Validar que el índice de fila exista dentro de los límites de la matriz
        if (fila < 0 || fila >= matriz.GetLength(0))
        {
            throw new IndexOutOfRangeException("El índice de fila está fuera de los límites de la matriz.");
        }

        int suma = 0;
        int columnas = matriz.GetLength(1); // Obtiene la cantidad de columnas

        // Recorrer todas las columnas de la fila indicada
        for (int col = 0; col < columnas; col++)
        {
            suma += matriz[fila, col];
        }

        return suma;
    }
}
