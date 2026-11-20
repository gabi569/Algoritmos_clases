using System;
using System.Collections.Generic;

namespace GestionArcade
{
    // Definición de la estructura con exactamente 3 campos: string, int y double
    struct MaquinaArcade
    {
        public string NombreJuego;
        public int PartidasJugadas;
        public double PrecioFicha;
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<MaquinaArcade> listaMaquinas = new List<MaquinaArcade>();
            int opcion = 0;

            while (opcion != 8)
            {
                Console.Clear();
                Console.WriteLine("==========================================");
                Console.WriteLine("       SISTEMA DE SALÓN ARCADE        ");
                Console.WriteLine("==========================================");
                Console.WriteLine("1. Registrar nueva máquina arcade");
                Console.WriteLine("2. Mostrar todas las máquinas registradas");
                Console.WriteLine("3. Calcular promedio del precio de ficha");
                Console.WriteLine("4. Buscar máquina por nombre");
                Console.WriteLine("5. Mostrar máquinas con ficha superior al promedio");
                Console.WriteLine("6. Mostrar máquina con ficha máxima y mínima");
                Console.WriteLine("7. Eliminar una máquina por su nombre");
                Console.WriteLine("8. Salir del programa");
                Console.WriteLine("==========================================");
                Console.Write("Seleccione una opción (1-8): ");

                try
                {
                    opcion = int.Parse(Console.ReadLine());
                }
                catch
                {
                    opcion = 0; // Fuerza caer en el default si no ingresa un número
                }

                Console.Clear();

                switch (opcion)
                {
                    case 1:
                        Console.WriteLine("--- 1. REGISTRAR NUEVA MÁQUINA ---");
                        // TODO: Pedir NombreJuego (string).
                        // TODO: Pedir PartidasJugadas (int) y PrecioFicha (double) dentro de un bloque try-catch.
                        // TODO: Crear una variable de tipo MaquinaArcade, asignar los valores y agregarla a listaMaquinas.
                        break;

                    case 2:
                        Console.WriteLine("--- 2. LISTADO DE MÁQUINAS ARCADE ---");
                        // TODO: Verificar si listaMaquinas.Count == 0.
                        // TODO: Recorrer listaMaquinas con un foreach o for y mostrar los 3 campos de cada elemento.
                        break;

                    case 3:
                        Console.WriteLine("--- 3. PROMEDIO DE PRECIO DE FICHA ---");
                        // TODO: Validar que la lista no esté vacía para evitar división por cero.
                        // TODO: Sumar todos los PrecioFicha, dividir por listaMaquinas.Count y mostrar el resultado.
                        break;

                    case 4:
                        Console.WriteLine("--- 4. BUSCAR MÁQUINA POR NOMBRE ---");
                        // TODO: Pedir al usuario el nombre del juego a buscar.
                        // TODO: Recorrer la lista comparando NombreJuego (puedes usar .ToLower() o StringComparison.OrdinalIgnoreCase).
                        // TODO: Mostrar sus datos si se encuentra, o informar que no existe.
                        break;

                    case 5:
                        Console.WriteLine("--- 5. MÁQUINAS CON FICHA SUPERIOR AL PROMEDIO ---");
                        // TODO: Calcular el promedio de PrecioFicha (igual que en el caso 3).
                        // TODO: Recorrer la lista y mostrar solo las máquinas donde PrecioFicha > promedio.
                        break;

                    case 6:
                        Console.WriteLine("--- 6. FICHA MÁS CARA Y MÁS BARATA ---");
                        // TODO: Validar que la lista tenga al menos 1 elemento.
                        // TODO: Inicializar variables max y min con el primer elemento de la lista (listaMaquinas[0]).
                        // TODO: Recorrer la lista comparando PrecioFicha para encontrar el máximo y el mínimo, y mostrarlos.
                        break;

                    case 7:
                        Console.WriteLine("--- 7. ELIMINAR MÁQUINA POR NOMBRE ---");
                        // TODO: Pedir el nombre del juego a eliminar.
                        // TODO: Buscar el índice o elemento en listaMaquinas y eliminarlo con .RemoveAt() o .Remove().
                        // TODO: Mostrar un mensaje confirmando si se eliminó o si no se encontró.
                        break;

                    case 8:
                        Console.WriteLine("Cerrando el sistema del Salón Arcade... ¡Hasta luego!");
                        break;

                    default:
                        Console.WriteLine(" Opción inválida. Por favor, ingrese un número del 1 al 8.");
                        break;
                }

                if (opcion != 8)
                {
                    Console.WriteLine("\nPresione cualquier tecla para volver al menú...");
                    Console.ReadKey();
                }
            }
        }
    }
}
