using System;
using System.Collections.Generic;

namespace TiendaVideojuegos
{
    class Program
    {
        // Constantes de capacidad máxima
        const int MAX_JUEGOS = 10;
        const int MAX_VENTAS = 50;

        // 1. Estructuras para el Inventario (Arreglos paralelos)
        static string[] nombresJuegos = new string[MAX_JUEGOS];
        static double[] preciosJuegos = new double[MAX_JUEGOS];
        static int[] stockJuegos = new int[MAX_JUEGOS];
        static int cantidadJuegosActual = 0;

        // 2. Estructura para Clientes en Espera (Cola)
        static Queue<string> colaClientes = new Queue<string>();

        // 3. Estructura para Ventas Diarias (Matriz: [fila, 0]=IdJuego, [fila, 1]=Cantidad, [fila, 2]=Total)
        static double[,] matrizVentas = new double[MAX_VENTAS, 3];
        static int cantidadVentasActual = 0;

        static void Main(string[] args)
        {
            InicializarInventario();
            int opcion = 0;

            do
            {
                MostrarMenu();
                if (int.TryParse(Console.ReadLine(), out opcion))
                {
                    Console.Clear();
                    EjecutarOpcion(opcion);
                }
                else
                {
                    Console.WriteLine("Por favor, ingrese un número válido.");
                }

                if (opcion != 6)
                {
                    Console.WriteLine("\nPresione cualquier tecla para continuar...");
                    Console.ReadKey();
                    Console.Clear();
                }

            } while (opcion != 6);
        }

        static void InicializarInventario()
        {
            AgregarJuegoAlSistema("The Legend of Zelda", 59.99, 10);
            AgregarJuegoAlSistema("God of War", 49.99, 8);
            AgregarJuegoAlSistema("Elden Ring", 69.99, 5);
            AgregarJuegoAlSistema("Minecraft", 29.99, 15);
        }

        static void MostrarMenu()
        {
            Console.WriteLine("=========================================");
            Console.WriteLine("   SISTEMA DE GESTIÓN - TIENDA GAMER     ");
            Console.WriteLine("=========================================");
            Console.WriteLine("1. Ver inventario de videojuegos");
            Console.WriteLine("2. Agregar nuevo videojuego al inventario");
            Console.WriteLine("3. Registrar cliente en la fila de espera");
            Console.WriteLine("4. Atender al siguiente cliente (Realizar venta)");
            Console.WriteLine("5. Ver reporte de ventas diarias");
            Console.WriteLine("6. Salir");
            Console.Write("Seleccione una opción: ");
        }

        static void EjecutarOpcion(int opcion)
        {
            switch (opcion)
            {
                case 1:
                    MostrarInventario();
                    break;
                case 2:
                    SolicitarNuevoJuego();
                    break;
                case 3:
                    RegistrarCliente();
                    break;
                case 4:
                    AtenderCliente();
                    break;
                case 5:
                    MostrarReporteVentas();
                    break;
                case 6:
                    Console.WriteLine("Cerrando sistema. ¡Hasta luego!");
                    break;
                default:
                    Console.WriteLine("Opción no válida. Intente nuevamente.");
                    break;
            }
        }

        // --- PROCEDIMIENTOS DE INVENTARIO ---

        static void MostrarInventario()
        {
            Console.WriteLine("--- INVENTARIO ACTUAL ---");
            Console.WriteLine("ID\tNombre\t\t\tPrecio\t\tStock");
            Console.WriteLine("---------------------------------------------------------");
            for (int i = 0; i < cantidadJuegosActual; i++)
            {
                Console.WriteLine($"{i}\t{nombresJuegos[i],-20}\t${preciosJuegos[i]:F2}\t\t{stockJuegos[i]}");
            }
        }

        static void SolicitarNuevoJuego()
        {
            if (cantidadJuegosActual >= MAX_JUEGOS)
            {
                Console.WriteLine("El inventario está lleno. No se pueden agregar más títulos.");
                return;
            }

            Console.Write("Ingrese el nombre del videojuego: ");
            string nombre = Console.ReadLine();

            Console.Write("Ingrese el precio: ");
            double precio = double.Parse(Console.ReadLine());

            Console.Write("Ingrese el stock inicial: ");
            int stock = int.Parse(Console.ReadLine());

            AgregarJuegoAlSistema(nombre, precio, stock);
            Console.WriteLine("Videojuego agregado exitosamente.");
        }

        static void AgregarJuegoAlSistema(string nombre, double precio, int stock)
        {
            nombresJuegos[cantidadJuegosActual] = nombre;
            preciosJuegos[cantidadJuegosActual] = precio;
            stockJuegos[cantidadJuegosActual] = stock;
            cantidadJuegosActual++;
        }

        // --- PROCEDIMIENTOS DE COLA DE CLIENTES ---

        static void RegistrarCliente()
        {
            Console.Write("Ingrese el nombre del cliente que llega a la fila: ");
            string cliente = Console.ReadLine();
            
            colaClientes.Enqueue(cliente);
            Console.WriteLine($"Cliente '{cliente}' agregado a la fila. Clientes en espera: {colaClientes.Count}");
        }

        // --- PROCEDIMIENTOS DE VENTAS (MATRIZ) ---

        static void AtenderCliente()
        {
            if (colaClientes.Count == 0)
            {
                Console.WriteLine("No hay clientes esperando en la fila.");
                return;
            }

            if (cantidadVentasActual >= MAX_VENTAS)
            {
                Console.WriteLine("Se alcanzó el límite máximo de ventas diarias.");
                return;
            }

            // Extraer al primer cliente de la cola (FIFO)
            string clienteActual = colaClientes.Dequeue();
            Console.WriteLine($"Atendiendo a: {clienteActual}\n");

            MostrarInventario();

            Console.Write("\nIngrese el ID del juego que desea comprar: ");
            int idJuego = int.Parse(Console.ReadLine());

            if (idJuego < 0 || idJuego >= cantidadJuegosActual)
            {
                Console.WriteLine("ID de juego inválido. Venta cancelada.");
                return;
            }

            Console.Write($"Ingrese la cantidad de copias de '{nombresJuegos[idJuego]}': ");
            int cantidad = int.Parse(Console.ReadLine());

            if (cantidad <= 0 || cantidad > stockJuegos[idJuego])
            {
                Console.WriteLine("Stock insuficiente o cantidad inválida. Venta cancelada.");
                return;
            }

            // Actualizar stock y registrar en la matriz de ventas
            stockJuegos[idJuego] -= cantidad;
            double totalVenta = preciosJuegos[idJuego] * cantidad;

            matrizVentas[cantidadVentasActual, 0] = idJuego;
            matrizVentas[cantidadVentasActual, 1] = cantidad;
            matrizVentas[cantidadVentasActual, 2] = totalVenta;
            cantidadVentasActual++;

            Console.WriteLine($"\n¡Venta exitosa! Total cobrado a {clienteActual}: ${totalVenta:F2}");
        }

        static void MostrarReporteVentas()
        {
            Console.WriteLine("--- REPORTE DE VENTAS DIARIAS ---");
            if (cantidadVentasActual == 0)
            {
                Console.WriteLine("Aún no se han registrado ventas hoy.");
                return;
            }

            double recaudacionTotal = 0;
            Console.WriteLine("N° Venta\tJuego\t\t\tCantidad\tTotal");
            Console.WriteLine("----------------------------------------------------------------");

            for (int i = 0; i < cantidadVentasActual; i++)
            {
                int idJuego = (int)matrizVentas[i, 0];
                int cantidad = (int)matrizVentas[i, 1];
                double subtotal = matrizVentas[i, 2];
                recaudacionTotal += subtotal;

                Console.WriteLine($"{i + 1}\t\t{nombresJuegos[idJuego],-20}\t{cantidad}\t\t${subtotal:F2}");
            }

            Console.WriteLine("----------------------------------------------------------------");
            Console.WriteLine($"RECAUDACIÓN TOTAL DEL DÍA: ${recaudacionTotal:F2}");
        }
    }
}
