# Proyecto Cliente-Servidor con Cifrado

Este proyecto implementa una arquitectura cliente-servidor utilizando sockets TCP en C++ con cifrado AES y RSA. El servidor y el cliente se comunican de manera segura a través de un canal cifrado, y ambos intercambian claves públicas para establecer la comunicación de manera segura.

## Descripción

El servidor espera conexiones de un cliente, intercambia claves públicas para establecer un canal seguro y luego puede enviar y recibir mensajes cifrados usando AES. El cliente, por su parte, también cifra los mensajes antes de enviarlos y descifra los mensajes recibidos del servidor.

### Componentes

1. **Servidor**:
   - Inicia un socket para escuchar en un puerto específico.
   - Espera a que un cliente se conecte.
   - Intercambia claves públicas con el cliente.
   - Recibe mensajes cifrados, los descifra y los muestra.
   - Envia mensajes cifrados al cliente.
   
2. **Cliente**:
   - Se conecta al servidor mediante una dirección IP y puerto específicos.
   - Intercambia claves públicas con el servidor.
   - Envia mensajes cifrados al servidor.
   - Recibe y descifra los mensajes enviados por el servidor.

## Funcionalidad

### Cliente
- **Conexión al servidor**: El cliente se conecta al servidor mediante un socket TCP utilizando una dirección IP y un puerto.
- **Intercambio de claves públicas**: El cliente y el servidor intercambian sus claves públicas para establecer un canal seguro.
- **Cifrado de mensajes**: Los mensajes enviados desde el cliente al servidor son cifrados utilizando una clave AES.
- **Descifrado de mensajes**: Los mensajes cifrados recibidos del servidor se descifran utilizando la clave AES.

### Servidor
- **Esperando cliente**: El servidor escucha un puerto y espera que el cliente se conecte.
- **Intercambio de claves públicas**: El servidor intercambia claves públicas con el cliente para garantizar una comunicación segura.
- **Recepción y descifrado de mensajes**: El servidor recibe los mensajes cifrados, los descifra y los muestra.
- **Envío de mensajes cifrados**: El servidor puede enviar mensajes cifrados al cliente.

## Requisitos

- **Winsock2**: La implementación utiliza la biblioteca `Ws2_32.lib` para manejar conexiones de red en sistemas Windows.
- **C++11** o superior: El proyecto hace uso de hilos (`std::thread`) y otras características modernas de C++.
- **Bibliotecas de criptografía**: Se utiliza AES y RSA para el cifrado de datos.


```bash
./server [puerto]
