using System;

class Program
{
    static void Main()
    {
        // Matriz de ejemplo de 3x3
        int[,] matriz = {
            { 10, 20, 30 },
            { 40, 50, 60 },
            { 70, 80, 90 }
        };

        int numeroBuscado = 50;

        // Llamamos al método
        var posicion = BuscarEnMatriz(matriz, numeroBuscado);

        // Evaluamos el resultado
        if (posicion.fila != -1)
        {
            Console.WriteLine($"El número {numeroBuscado} se encuentra en la fila {posicion.fila}, columna {posicion.columna}.");
        }
        else
        {
            Console.WriteLine($"El número {numeroBuscado} no se encuentra en la matriz.");
        }
    }

    /// <summary>
    /// Busca un entero dentro de una matriz bidimensional y devuelve su posición.
    /// </summary>
    /// <returns>Una tupla (fila, columna) con los índices, o (-1, -1) si no existe.</returns>
    static (int fila, int columna) BuscarEnMatriz(int[,] matriz, int objetivo)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (matriz[i, j] == objetivo)
                {
                    return (i, j); // Retorna la posición apenas lo encuentra
                }
            }
        }

        // Valor que indica que el elemento no está en la matriz
        return (-1, -1);
    }
}
