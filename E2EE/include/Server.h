#pragma once
#include "NetworkHelper.h"
#include "CryptoHelper.h"
#include "Prerequisites.h"

/**
 * @brief Clase que maneja la implementaci�n de un servidor para intercambiar mensajes cifrados con un cliente.
 *        Incluye m�todos para la gesti�n de la conexi�n, intercambio de claves y cifrado/descifrado de mensajes.
 */
class Server {
public:
    /**
     * @brief Constructor por defecto.
     */
    Server() = default;

    /**
     * @brief Constructor que inicializa el puerto del servidor.
     * @param port Puerto donde el servidor escuchar� conexiones entrantes.
     */
    Server(int port);

    /**
     * @brief Destructor que cierra los recursos del servidor.
     */
    ~Server();

    /**
     * @brief Inicia el servidor en el puerto especificado.
     * @return true si el servidor se inicializ� correctamente.
     * @return false si hubo un error durante la inicializaci�n del servidor.
     */
    bool 
    Start();

    /**
     * @brief Espera a que un cliente se conecte e intercambia claves p�blicas para asegurar la comunicaci�n.
     * @note El servidor no podr� enviar ni recibir datos hasta que el intercambio de claves se complete.
     */
    void 
    WaitForClient();

    /**
     * @brief Recibe un mensaje cifrado del cliente, lo descifra y lo imprime.
     * @note Este m�todo maneja el proceso de descifrado de los mensajes cifrados recibidos.
     */
    void 
    ReceiveEncryptedMessage();

    /**
     * @brief Inicia el ciclo de recepci�n de mensajes en un hilo independiente.
     * @note Este ciclo permite que el servidor escuche continuamente los mensajes del cliente.
     */
    void 
    StartReceiveLoop();

    /**
     * @brief Envia un mensaje cifrado al cliente en un ciclo continuo.
     * @note Este ciclo permite que el servidor env�e mensajes cifrados al cliente en intervalos.
     */
    void 
    SendEncryptedMessageLoop();

    /**
     * @brief Inicia el ciclo de chat del servidor.
     * @note Este ciclo permite que el servidor reciba y env�e mensajes cifrados de forma interactiva.
     */
    void 
    StartChatLoop();

private:
    int m_port;               ///< Puerto en el cual el servidor escuchar� conexiones.
    SOCKET m_clientSock;      ///< Socket que maneja la conexi�n con el cliente.
    NetworkHelper m_net;      ///< Objeto encargado de gestionar las operaciones de red.
    CryptoHelper m_crypto;    ///< Objeto que maneja las operaciones criptogr�ficas.
    std::thread m_rxThread;   ///< Hilo para recibir mensajes de forma asincr�nica.
    std::atomic<bool> m_running{ false }; ///< Indicador de si el servidor est� en ejecuci�n.
};
