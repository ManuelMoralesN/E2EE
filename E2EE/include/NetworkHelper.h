#pragma once
#include "Prerequisites.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

/**
 * @brief Clase que proporciona funciones de red para conectar, enviar y recibir datos usando sockets.
 *        Soporta tanto el modo servidor como cliente.
 */
class NetworkHelper {
public:
    /**
     * @brief Constructor que inicializa los recursos de la red.
     */
    NetworkHelper();

    /**
     * @brief Destructor que cierra los sockets y libera los recursos.
     */
    ~NetworkHelper();

    /**
     * @brief Inicia un socket servidor en el puerto indicado y lo deja en modo escucha.
     * @param port Puerto TCP que se usará para escuchar conexiones entrantes.
     * @return true Si el servidor se inicia correctamente.
     * @return false Si ocurre un error en cualquier paso.
     */
    bool 
    StartServer(int port);

    /**
     * @brief Espera y acepta un cliente entrante.
     * @return SOCKET Socket del cliente aceptado, o INVALID_SOCKET si falla.
     */
    SOCKET AcceptClient();

    // Modo cliente

    /**
     * @brief Conecta al servidor especificado por IP y puerto.
     * @param ip Dirección IP del servidor.
     * @param port Puerto del servidor.
     * @return true Si la conexión fue exitosa.
     * @return false Si falló la conexión.
     */
    bool 
    ConnectToServer(const std::string& ip, int port);

    // Enviar y recibir datos

    /**
     * @brief Envía una cadena de texto por el socket.
     * @param socket El socket por el que se enviarán los datos.
     * @param data Cadena de texto que se enviará.
     * @return true Si los datos se envían correctamente.
     * @return false Si ocurrió un error durante el envío.
     */
    bool 
    SendData(SOCKET socket, const std::string& data);

    /**
     * @brief Envía datos binarios (por ejemplo, cifrados con AES, RSA) por el socket.
     * @param socket El socket por el que se enviarán los datos.
     * @param data Datos binarios que se enviarán.
     * @return true Si los datos se envían correctamente.
     * @return false Si ocurrió un error durante el envío.
     */
    bool 
    SendData(SOCKET socket, const std::vector<unsigned char>& data);

    /**
     * @brief Recibe una cadena de texto del socket.
     * @param socket El socket desde el cual se recibirán los datos.
     * @return Cadena de texto recibida del socket.
     */
    std::string ReceiveData(SOCKET socket);

    /**
     * @brief Recibe datos binarios (por ejemplo, AES, RSA) del socket.
     * @param socket El socket desde el cual se recibirán los datos.
     * @param size Cantidad de datos a recibir (por defecto 0, que significa todos los datos disponibles).
     * @return Datos binarios recibidos del socket.
     */
    std::vector<unsigned char> ReceiveDataBinary(SOCKET socket, int size = 0);

    /**
     * @brief Cierra una conexión de socket.
     * @param socket El socket que se cerrará.
     */
    void 
    close(SOCKET socket);

    /**
     * @brief Envía todos los datos a través del socket de forma segura.
     * @param s El socket por el cual se enviarán los datos.
     * @param data Los datos a enviar.
     * @param len Longitud de los datos a enviar.
     * @return true Si todos los datos se envían correctamente.
     * @return false Si ocurrió un error durante el envío.
     */
    bool 
    SendAll(SOCKET s, const unsigned char* data, int len);

    /**
     * @brief Recibe la cantidad exacta de datos especificada del socket.
     * @param s El socket desde el cual se recibirán los datos.
     * @param out Buffer donde se almacenarán los datos recibidos.
     * @param len Longitud de los datos que se deben recibir.
     * @return true Si se recibe la cantidad exacta de datos.
     * @return false Si ocurrió un error durante la recepción.
     */
    bool 
    ReceiveExact(SOCKET s, unsigned char* out, int len);

public:
    SOCKET m_serverSocket = -1; ///< Socket del servidor.

private:
    bool m_initialized; ///< Indica si la inicialización de la red fue exitosa.
};
