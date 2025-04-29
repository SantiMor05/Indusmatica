CREATE TABLE cliente (
    id_cliente       CHAR(10 BYTE) NOT NULL,
    razon_social     CHAR(25 BYTE),
    ruc              CHAR(11 BYTE),
    telefono         CHAR(11 BYTE),
    correo           CHAR(50 BYTE),
    direccion_fiscal CHAR(100 BYTE)
);

COMMENT ON COLUMN cliente.id_cliente IS
    'IDENTIFICADOR DEL CLIENTE.';
	
COMMENT ON COLUMN cliente.razon_social IS
    'RAZON SOCIAL DEL CLIENTE.';
	
COMMENT ON COLUMN cliente.ruc IS
    'RUC DEL CLIENTE.';

ALTER TABLE cliente ADD CONSTRAINT cliente_pk PRIMARY KEY ( id_cliente );


CREATE TABLE detalleordpedido (
    cantidad           NUMBER,
    en_stock           CHAR(1),
    id_ordenpedido     CHAR(10 BYTE) NOT NULL,
    tipobus_id_tipobus CHAR(10 BYTE) NOT NULL,
    id_detallepedido   CHAR(10 BYTE) NOT NULL,
    id_ordenproduccion CHAR(10 BYTE)
);

COMMENT ON COLUMN detalleordpedido.cantidad IS
    'CANTIDAD DEL PEDIDO.';
	
COMMENT ON COLUMN detalleordpedido.en_stock IS
    'INDICADOR DE SI HAY STOCK O NO.';



ALTER TABLE detalleordpedido ADD CONSTRAINT detalleordenpedido_pk PRIMARY KEY ( id_detallepedido,
                                                                                id_ordenpedido );



CREATE TABLE detalleordproduccion (
    articulo           CHAR(80 BYTE),
    cantidad           NUMBER,
    unidad             CHAR(2 BYTE),
    id_ordenproduccion CHAR(10 BYTE) NOT NULL
);

COMMENT ON COLUMN detalleordproduccion.cantidad IS
    'CANTIDAD DEL PEDIDO.';
	
COMMENT ON COLUMN detalleordproduccion.articulo IS
    'DESCRIPCION DEL ARTICULO DE LA ORDEN DE PRODUCCION.';

COMMENT ON COLUMN detalleordproduccion.unidad IS
    'INDICA LA UNIDAD DEL ARTICULO.';


CREATE TABLE formapago (
    id_formapago CHAR(10 BYTE) NOT NULL,
    nombre       CHAR(120 BYTE),
    moneda       CHAR(4 BYTE)
);

COMMENT ON COLUMN formapago.id_formapago IS
    'IDENTIFICADOR DE LA FORMA DE PAGO.';
	
COMMENT ON COLUMN formapago.nombre IS
    'DESCRIPCION DE LA FORMA DE PAGO.';
	
COMMENT ON COLUMN formapago.moneda IS
    'INDICADOR DE LA MONEDA DE LA FORMA DE PAGO.';

ALTER TABLE formapago ADD CONSTRAINT formapago_pk PRIMARY KEY ( id_formapago );


CREATE TABLE ordenpedido (
    id_ordenpedido         CHAR(10 BYTE) NOT NULL,
    fecha_registro          DATE,
    fecha_entrega          DATE,
    cliente_id_cliente     CHAR(10 BYTE) NOT NULL,
    sede_id_sede           CHAR(10 BYTE) NOT NULL,
    formapago_id_formapago CHAR(10 BYTE) NOT NULL
);

ALTER TABLE ordenpedido ADD CONSTRAINT ordenpedido_pk PRIMARY KEY ( id_ordenpedido );


CREATE TABLE ordenproduccion (
    id_ordenproduccion CHAR(10 BYTE) NOT NULL,
    fecha_registro     DATE,
    fecha_inicio       DATE NOT NULL,
    fecha_culminacion  DATE,
    id_personal_acargo  CHAR(8),
    especificacion     CHAR(200 BYTE)
);

ALTER TABLE ordenproduccion ADD CONSTRAINT ordenproduccion_pk PRIMARY KEY ( id_ordenproduccion );


CREATE TABLE sede (
    id_sede    CHAR(10 BYTE) NOT NULL,
    nombresede CHAR(150 BYTE),
    distrito   CHAR(20 BYTE),
    provincia  CHAR(50 BYTE),
    area       NUMBER,
    direccion  CHAR(120 BYTE),
    telefono  CHAR(11 CHAR)
);

ALTER TABLE sede ADD CONSTRAINT sede_pk PRIMARY KEY ( id_sede );



 CREATE TABLE tipobus (
    id_tipobus CHAR(10 BYTE) NOT NULL,
    nombre     CHAR(120 BYTE)
);

ALTER TABLE tipobus ADD CONSTRAINT tipobus_pk PRIMARY KEY ( id_tipobus );


ALTER TABLE detalleordpedido
    ADD CONSTRAINT detalordpedido_ordenpedido_fk FOREIGN KEY ( id_ordenpedido )
        REFERENCES ordenpedido ( id_ordenpedido );

ALTER TABLE detalleordpedido
    ADD CONSTRAINT detalordpedido_ordproduc_fk FOREIGN KEY ( id_ordenproduccion )
        REFERENCES ordenproduccion ( id_ordenproduccion );

ALTER TABLE detalleordpedido
    ADD CONSTRAINT detalordpedido_tipobus_fk FOREIGN KEY ( tipobus_id_tipobus )
        REFERENCES tipobus ( id_tipobus );

ALTER TABLE detalleordproduccion
    ADD CONSTRAINT detalordproduc_ordenproduc_fk FOREIGN KEY ( id_ordenproduccion )
        REFERENCES ordenproduccion ( id_ordenproduccion );
		
ALTER TABLE ordenpedido
    ADD CONSTRAINT ordenpedido_cliente_fk FOREIGN KEY ( cliente_id_cliente )
        REFERENCES cliente ( id_cliente );

ALTER TABLE ordenpedido
    ADD CONSTRAINT ordenpedido_formapago_fk FOREIGN KEY ( formapago_id_formapago )
        REFERENCES formapago ( id_formapago );

ALTER TABLE ordenpedido
    ADD CONSTRAINT ordenpedido_sede_fk FOREIGN KEY ( sede_id_sede )
        REFERENCES sede ( id_sede );



