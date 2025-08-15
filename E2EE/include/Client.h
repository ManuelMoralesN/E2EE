#pragma once
#include "NetworkHelper.h"
#include "CryptoHelper.h"
#include "Prerequisites.h"

/**
 * @brief Clase que maneja la conexión de un cliente a un servidor, incluyendo la encriptación de mensajes y el intercambio de claves.
 */
class Client {
public:
    /**
     * @brief Constructor por defecto.
     */
    Client() = default;

    /**
     * @brief Constructor que inicializa la dirección IP y el puerto del servidor.
     * @param ip Dirección IP del servidor.
     * @param port Puerto del servidor.
     */
    Client(const std::string& ip, int port);

    /**
     * @brief Destructor por defecto.
     */
    ~Client();

    /**
     * @brief Establece la conexión con el servidor.
     * @return true si la conexión fue exitosa.
     * @return false si ocurrió un error al intentar conectarse.
     */
    bool 
    Connect();

    /**
     * @brief Intercambia claves públicas con el servidor para establecer un canal seguro.
     * @note Este paso es necesario antes de cifrar cualquier mensaje.
     */
    void 
    ExchangeKeys();

    /**
     * @brief Cifra la clave AES con la clave pública del servidor y la envía al servidor.
     * @note Esta clave AES será utilizada para cifrar los mensajes subsiguientes.
     */
    void 
    SendAESKeyEncrypted();

    /**
     * @brief Cifra un mensaje utilizando AES y lo envía al servidor.
     * @param message Texto plano que se desea cifrar y enviar.
     * @note El mensaje se cifra antes de ser enviado al servidor para mantener la seguridad.
     */
    void 
    SendEncryptedMessage(const std::string& message);

    /**
     * @brief Envia mensajes cifrados en un ciclo continuo hasta que se decida detener la conexión.
     * @note Este ciclo permite al cliente enviar múltiples mensajes cifrados al servidor.
     */
    void 
    SendEncryptedMessageLoop();

    /**
     * @brief Inicia el ciclo de chat del cliente.
     * @note Este método permite al cliente interactuar con el servidor en un entorno de chat.
     */
    void 
    StartChatLoop();

    /**
     * @brief Inicia el ciclo para recibir mensajes desde el servidor.
     * @note Este método escucha mensajes del servidor y los muestra al usuario.
     */
    void 
    StartReceiveLoop();

private:
    std::string m_ip;               ///< Dirección IP del servidor.
    int m_port;                     ///< Puerto del servidor.
    SOCKET m_serverSock;            ///< Socket de conexión con el servidor.
    NetworkHelper m_net;            ///< Objeto para ayudar con la comunicación de red.
    CryptoHelper m_crypto;          ///< Objeto para manejar operaciones criptográficas.
};
