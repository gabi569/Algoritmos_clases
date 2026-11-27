using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo (3 filas x 4 columnas)
        int[,] matriz = {
            { 1,  2,  3,  4 },
            { 5,  6,  7,  8 },
            { 9, 10, 11, 12 }
        };

        int columnaAcalcular = 2; // Debería sumar: 3 + 7 + 11 = 21

        try
        {
            int resultado = SumarColumna(matriz, columnaAcalcular);
            Console.WriteLine($"La suma de los elementos de la columna {columnaAcalcular} es: {resultado}");
        }
        catch (ArgumentOutOfRangeException ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    /// <summary>
    /// Calcula la suma de los elementos de una columna específica en una matriz de enteros.
    /// </summary>
    static int SumarColumna(int[,] matriz, int indiceColumna)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        // Validación de seguridad para evitar desbordamiento de índice
        if (indiceColumna < 0 || indiceColumna >= columnas)
        {
            throw new ArgumentOutOfRangeException(nameof(indiceColumna), "El índice de columna está fuera de los límites de la matriz.");
        }

        int suma = 0;

        // Recorremos todas las filas manteniendo fija la columna
        for (int i = 0; i < filas; i++)
        {
            suma += matriz[i, indiceColumna];
        }

        return suma;
    }
}
