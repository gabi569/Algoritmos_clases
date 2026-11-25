using System;

class Program
{
    static void Main(string[] args)
    {
        // ==========================================
        // 1. Validador de Mayores
        // ==========================================
        Console.WriteLine("--- Ejercicio 1: Validador de Mayores ---");
        Console.Write("Ingresa tu edad: ");
        if (int.TryParse(Console.ReadLine(), out int edadUsuario))
        {
            bool esMayor = EsMayorDeEdad(edadUsuario);
            Console.WriteLine($"¿Es mayor de edad?: {esMayor}\n");
        }

        // ==========================================
        // 2. Conversor de Temperaturas
        // ==========================================
        Console.WriteLine("--- Ejercicio 2: Conversor de Temperaturas ---");
        Console.WriteLine("1. Celsius a Fahrenheit");
        Console.WriteLine("2. Fahrenheit a Celsius");
        Console.Write("Elige una opción (1 o 2): ");
        string opcion = Console.ReadLine();

        if (opcion == "1")
        {
            Console.Write("Ingresa los grados Celsius: ");
            double celsius = Convert.ToDouble(Console.ReadLine());
            double fahrenheit = CelsiusAFahrenheit(celsius);
            Console.WriteLine($"Resultado: {celsius}°C equivalen a {fahrenheit}°F\n");
        }
        else if (opcion == "2")
        {
            Console.Write("Ingresa los grados Fahrenheit: ");
            double fahrenheit = Convert.ToDouble(Console.ReadLine());
            double celsius = FahrenheitACelsius(fahrenheit);
            Console.WriteLine($"Resultado: {fahrenheit}°F equivalen a {celsius}°C\n");
        }

        // ==========================================
        // 3. Calculador de Áreas Modular
        // ==========================================
        Console.WriteLine("--- Ejercicio 3: Calculador de Áreas ---");
        double radio = 5.0;
        double area = CalcularAreaCirculo(radio);
        ImprimirResultado("EL RESULTADO ES", area);
        Console.WriteLine();

        // ==========================================
        // 4. El Buscador de Máximos
        // ==========================================
        Console.WriteLine("--- Ejercicio 4: Buscador de Máximos ---");
        int maximo = ObtenerMaximo(15, 42, 23);
        Console.WriteLine($"El mayor entre 15, 42 y 23 es: {maximo}\n");

        // ==========================================
        // 5. Simulador de Cajero
        // ==========================================
        Console.WriteLine("--- Ejercicio 5: Simulador de Cajero ---");
        double saldoActual = 5000.0;
        Console.WriteLine($"Saldo inicial: ${saldoActual}");
        
        double montoRetiro = 1500.0;
        Console.WriteLine($"Intentando retirar: ${montoRetiro}");
        saldoActual = RealizarRetiro(saldoActual, montoRetiro);
        Console.WriteLine($"Saldo final: ${saldoActual}");
    }

    // ==========================================
    // DEFINICIÓN DE FUNCIONES
    // ==========================================

    // 1. EsMayorDeEdad
    public static bool EsMayorDeEdad(int edad)
    {
        return edad >= 18;
    }

    // 2. Conversiones
    public static double CelsiusAFahrenheit(double celsius)
    {
        return (celsius * 9.0 / 5.0) + 32;
    }

    public static double FahrenheitACelsius(double fahrenheit)
    {
        return (fahrenheit - 32) * 5.0 / 9.0;
    }

    // 3. Áreas e impresión
    public static double CalcularAreaCirculo(double radio)
    {
        return Math.PI * (radio * radio);
    }

    public static void ImprimirResultado(string texto, double numero)
    {
        Console.WriteLine($"--- {texto}: {numero:F2} ---");
    }

    // 4. Buscador de Máximos (con estructuras if)
    public static int ObtenerMaximo(int a, int b, int c)
    {
        int mayor = a;

        if (b > mayor)
        {
            mayor = b;
        }

        if (c > mayor)
        {
            mayor = c;
        }

        return mayor;
    }

    // 5. Simulador de Cajero
    public static double RealizarRetiro(double saldo, double retiro)
    {
        if (retiro > saldo)
        {
            Console.WriteLine("Error: Fondos insuficientes para realizar el retiro.");
            return saldo; // Devuelve el saldo sin cambios
        }
        else
        {
            double nuevoSaldo = saldo - retiro;
            Console.WriteLine("¡Retiro exitoso!");
            return nuevoSaldo;
        }
    }
}
