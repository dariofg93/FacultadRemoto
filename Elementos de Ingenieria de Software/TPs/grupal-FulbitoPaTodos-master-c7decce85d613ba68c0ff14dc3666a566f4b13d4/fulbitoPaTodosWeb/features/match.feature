Feature: Administracion de partidos

    Scenario: Listar todos los partidos
        Given No tengo partidos
        And No tengo usuarios
        And Un usuario con mail "lucas@lucas.com" y passwd "123456"
        And Un partido en Quilmes el 2018-05-10 a las 19:30 creado por "lucas@lucas.com"
        And Un partido en Lanus el 2018-01-02 a las 11:00 creado por "victor@victor.com"
        When Voy a listar todos los partidos
        And Lleno "user_email" con "lucas@lucas.com"
        And Lleno "user_password" con "123456"
        And Presiono "Iniciar Sesíon"
        And Voy a listar todos los partidos
        Then Deberia ver "Quilmes"
        And Deberia ver "2018-05-10"
        And Deberia ver "19:30"
        And Deberia ver "Lanus"
        And Deberia ver "2018-01-02"
        And Deberia ver "11:00"

    Scenario: Crear un partido
        Given No tengo partidos
        And No tengo usuarios
        And Un usuario con mail "lucas@lucas.com" y passwd "123456"
        And Voy a listar todos los partidos
        And Lleno "user_email" con "lucas@lucas.com"
        And Lleno "user_password" con "123456"
        And Presiono "Iniciar Sesíon"
        When Voy a listar todos los partidos
        And Voy a "Nuevo Partido"
        And Lleno "Place" con "Berazategui"
        And Lleno "Date" con "2050-10-06"
        And Lleno "Time" con "10:00"
        And Presiono "Crear Partido"
        Then Deberia ver "Nuevo Partido Creado!"
        And Deberia ver "Berazategui"
        And Deberia ver "2050-10-06"
        And Deberia ver "10:00"
        And Deberia tener 1 partidos

    Scenario: Unirse a un partido
        Given No tengo partidos
        And No tengo usuarios
        And Un usuario con mail "victor@victor.com" y passwd "123456"
        And Un usuario con mail "lucas@lucas.com" y passwd "123456"
        And Un partido en Quilmes el 2018-05-10 a las 19:30 creado por "victor@victor.com"
        And Voy a listar todos los partidos
        And Lleno "user_email" con "lucas@lucas.com"
        And Lleno "user_password" con "123456"
        And Presiono "Iniciar Sesíon"
        And Voy a listar todos los partidos
        When Voy a "Quilmes2018-05-1019:30"
        And Presiono "OK"
        Then Deberia ver "Te Uniste Al Partido!"
        And Deberia ver "lucas@lucas.com"
        And Deberia tener 1 partidos

    Scenario: Crear un partido y unir dos jugadores
        Given No tengo partidos
        And No tengo usuarios
        And Un usuario con mail "victor@victor.com" y passwd "123456"
        And Un usuario con mail "lucas@lucas.com" y passwd "123456"
        And Un partido en Quilmes el 2018-05-10 a las 20:30 creado por "victor@victor.com"
        When Voy a listar todos los partidos
        And Lleno "user_email" con "lucas@lucas.com"
        And Lleno "user_password" con "123456"
        And Presiono "Iniciar Sesíon"
        And Voy a listar todos los partidos
        And Voy a "Quilmes2018-05-1020:30"
        And Presiono "OK"
        Then Deberia ver "Te Uniste Al Partido!"
        And Deberia ver "lucas@lucas.com"
        And Deberia ver "victor@victor.com"
        And Deberia tener 1 partidos

    Scenario: Crear dos usuarios un partido y unir ambos usuarios al partido
        Given No tengo partidos
        And No tengo usuarios
        When Voy a listar todos los partidos
        And Voy a "Registrarse"
        And Lleno "user_email" con "lucas@lucas.com"
        And Lleno "user_password" con "123456"
        And Lleno "user_password_confirmation" con "123456"
        And Presiono "Registrarse"
        And Voy a listar todos los partidos
        And Voy a "Nuevo Partido"
        And Lleno "Place" con "Quilmes"
        And Lleno "Date" con "2018-02-02"
        And Lleno "Time" con "20:15"
        And Presiono "Crear Partido"
        And Voy a "Salir"
        And Voy a listar todos los partidos
        And Voy a "Registrarse"
        And Lleno "user_email" con "victor@victor.com"
        And Lleno "user_password" con "123456"
        And Lleno "user_password_confirmation" con "123456"
        And Presiono "Registrarse"
        And Voy a listar todos los partidos
        And Voy a "Quilmes2018-02-0220:15"
        And Presiono "OK"
        Then Deberia ver "Te Uniste Al Partido!"
        And Deberia ver "lucas@lucas.com"
        And Deberia ver "victor@victor.com"
        And Deberia tener 1 partidos

    Scenario: 1 partido exclusivo
        Given No tengo partidos
        And No tengo usuarios
        And No tengo suscripciones
        And Un usuario con mail "victor@victor.com" y passwd "123456"
        And Un usuario con mail "lucas@lucas.com" y passwd "123456"
        And Un partido EXCLUSIVO en Quilmes el 2018-05-10 a las 20:30 creado por "victor@victor.com"
        And Un partido en Berazategui el 2018-05-10 a las 20:30 creado por "lucas@lucas.com"
        When Voy a listar todos los partidos
        And Lleno "user_email" con "lucas@lucas.com"
        And Lleno "user_password" con "123456"
        And Presiono "Iniciar Sesíon"
        And Voy a listar todos los partidos
        And Voy a "Quilmes2018-05-1020:30"
        And Presiono "OK"
        Then Deberia ver "No te puedes unir a dos partidos en el mismo horario!"
