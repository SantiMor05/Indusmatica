CREATE TABLE CLIENTE (
    id_cliente       	CHAR(10 BYTE) NOT NULL,
    razon_social     	CHAR(80 BYTE),
    ruc              	CHAR(11 BYTE),    telefono         	CHAR(11 BYTE),
    correo           	CHAR(50 BYTE),
    direccion_fiscal 	CHAR(120 BYTE)
);

COMMENT ON COLUMN CLIENTE.ID_CLIENTE IS 'identificador del cliente.';
	
COMMENT ON COLUMN CLIENTE.RAZON_SOCIAL IS 'razon social del cliente.';
	
COMMENT ON COLUMN CLIENTE.RUC IS 'ruc del cliente.';

ALTER TABLE CLIENTE ADD CONSTRAINT CLIENTE_PK PRIMARY KEY ( ID_CLIENTE );


CREATE TABLE DETALLE_ORD_PEDIDO (
    id_detalle_pedido   CHAR(10 BYTE) NOT NULL,
	id_orden_pedido     CHAR(10 BYTE) NOT NULL,
	cantidad           	NUMBER,
    en_stock           	CHAR(1),
    id_orden_produccion CHAR(10 BYTE),
	id_tipo_bus 		CHAR(10 BYTE) NOT NULL
);

COMMENT ON COLUMN DETALLE_ORD_PEDIDO.CANTIDAD IS 'cantidad del pedido.';
	
COMMENT ON COLUMN DETALLE_ORD_PEDIDO.EN_STOCK IS 'indicador de si hay stock o no.';


ALTER TABLE DETALLE_ORD_PEDIDO ADD CONSTRAINT DETALLE_ORD_PEDIDO_PK PRIMARY KEY ( ID_DETALLE_PEDIDO, ID_ORDEN_PEDIDO );


CREATE TABLE DETALLE_ORD_PRODUCCION (
    id_detalle_ord_prod     CHAR(10 BYTE) NOT NULL,
    articulo                CHAR(80 BYTE),
    cantidad                NUMBER,
    unidad                  CHAR(2 BYTE),
    id_orden_produccion     CHAR(10 BYTE) NOT NULL
);

COMMENT ON COLUMN DETALLE_ORD_PRODUCCION.ID_ORDEN_PRODUCCION IS 'identificador de la orden de produccion';

COMMENT ON COLUMN DETALLE_ORD_PRODUCCION.CANTIDAD IS 'cantidad del pedido.';
	
COMMENT ON COLUMN DETALLE_ORD_PRODUCCION.ARTICULO IS 'descripcion del articulo de la orden de produccion.';

COMMENT ON COLUMN DETALLE_ORD_PRODUCCION.UNIDAD IS 'indica la unidad del articulo.';

ALTER TABLE DETALLE_ORD_PRODUCCION ADD CONSTRAINT DETALLE_ORD_PRODUCCION_PK PRIMARY KEY ( ID_DETALLE_ORD_PROD, ID_ORDEN_PRODUCCION );



CREATE TABLE FORMA_PAGO (
    id_forma_pago 			CHAR(10 BYTE) NOT NULL,
    nombre_forma_pago       CHAR(120 BYTE),
    moneda       			CHAR(4 BYTE)
);

COMMENT ON COLUMN FORMA_PAGO.ID_FORMA_PAGO IS 'identificador de la forma de pago.';
	
COMMENT ON COLUMN FORMA_PAGO.NOMBRE_FORMA_PAGO IS 'descripcion de la forma de pago.';
	
COMMENT ON COLUMN FORMA_PAGO.MONEDA IS 'indicador de la moneda de la forma de pago.';

ALTER TABLE FORMA_PAGO ADD CONSTRAINT FORMA_PAGO_PK PRIMARY KEY ( ID_FORMA_PAGO );


CREATE TABLE ORDEN_PEDIDO (
    id_orden_pedido     CHAR(10 BYTE) NOT NULL,
    fecha_registro      DATE,
    fecha_entrega       DATE,
    id_cliente     		CHAR(10 BYTE) NOT NULL,
    id_sede             CHAR(10 BYTE) NOT NULL,
    id_forma_pago 		CHAR(10 BYTE) NOT NULL
);

ALTER TABLE ORDEN_PEDIDO ADD CONSTRAINT ORDEN_PEDIDO_PK PRIMARY KEY ( ID_ORDEN_PEDIDO );


CREATE TABLE ORDEN_PRODUCCION (
    id_orden_produccion CHAR(10 BYTE) NOT NULL,
    fecha_registro     DATE,
    fecha_inicio       DATE NOT NULL,
    fecha_culminacion  DATE,
    id_personal_acargo NUMBER NOT NULL,
    especificacion     CHAR(200 BYTE)
);

ALTER TABLE ORDEN_PRODUCCION ADD CONSTRAINT ORDEN_PRODUCCION_PK PRIMARY KEY ( ID_ORDEN_PRODUCCION );


CREATE TABLE SEDE (
    id_sede    		CHAR(10 BYTE) NOT NULL,
    nombre_sede 	CHAR(150 BYTE),
    distrito   		CHAR(20 BYTE),
    provincia  		CHAR(50 BYTE),
    area_sede       		NUMBER,
    direccion  		CHAR(120 BYTE),
    telefono  		CHAR(11 CHAR), 
	codigo_postal 	VARCHAR2(6 BYTE),
    activo 			CHAR(1 BYTE)
);

ALTER TABLE SEDE ADD CONSTRAINT SEDE_PK PRIMARY KEY ( ID_SEDE );

COMMENT ON COLUMN SEDE.id_sede IS 'identificador de la sede';   	
COMMENT ON COLUMN SEDE.nombre_sede IS 'nombre de la sede'; 
COMMENT ON COLUMN SEDE.distrito IS 'nombre del distrito'; 	
COMMENT ON COLUMN SEDE.provincia IS 'nombre de la provincia';  	
COMMENT ON COLUMN SEDE.area_sede IS 'nombre del area en la sede';    
COMMENT ON COLUMN SEDE.direccion IS 'direccion fisica de la sede';  	
COMMENT ON COLUMN SEDE.telefono IS 'telefono principal de la seda';  	
COMMENT ON COLUMN SEDE.codigo_postal IS 'codigo postal de la sede';
COMMENT ON COLUMN SEDE.ACTIVO IS  'Identificador de si la sede esta activa: Si(S) o No(N)';


 CREATE TABLE TIPO_BUS (
    id_tipo_bus 	CHAR(10 BYTE) NOT NULL,
    nombre     		CHAR(120 BYTE)
);

COMMENT ON COLUMN TIPO_BUS.ID_TIPO_BUS IS 'identificador del tipo de bus';
COMMENT ON COLUMN TIPO_BUS.NOMBRE IS 'nombre comercial del tipo de bus';


ALTER TABLE TIPO_BUS ADD CONSTRAINT TIPO_BUS_PK PRIMARY KEY ( ID_TIPO_BUS );


ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT DETORDPEDIDO_ORDENPEDIDO_FK FOREIGN KEY ( ID_ORDEN_PEDIDO )
        REFERENCES ORDEN_PEDIDO ( ID_ORDEN_PEDIDO );

ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT DETORDPEDIDO_ORDPROD_FK FOREIGN KEY ( ID_ORDEN_PRODUCCION )
        REFERENCES ORDEN_PRODUCCION ( ID_ORDEN_PRODUCCION );

ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT DETORDPEDIDO_TIPOBUS_FK FOREIGN KEY ( ID_TIPO_BUS )
        REFERENCES TIPO_BUS ( ID_TIPO_BUS );


ALTER TABLE DETALLE_ORD_PRODUCCION
    ADD CONSTRAINT DETORDPRODUC_ORDENPRODUC_FK FOREIGN KEY ( ID_ORDEN_PRODUCCION )
        REFERENCES ORDEN_PRODUCCION ( ID_ORDEN_PRODUCCION );
		


		
ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT ORDEN_PEDIDO_CLIENTE_FK FOREIGN KEY ( ID_CLIENTE )
        REFERENCES CLIENTE ( ID_CLIENTE );
		

ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT ORDEN_PEDIDO_FORMA_PAGO_FK FOREIGN KEY ( ID_FORMA_PAGO )
        REFERENCES FORMA_PAGO ( ID_FORMA_PAGO );

ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT ORDEN_PEDIDO_SEDE_FK FOREIGN KEY ( ID_SEDE )
        REFERENCES SEDE ( ID_SEDE );



CREATE TABLE EMPLEADO(
    id_empleado NUMBER NOT NULL,
    nombre VARCHAR2(40 BYTE),
    ape_paterno VARCHAR2(40 BYTE),
    ape_materno VARCHAR2(40 BYTE),
    activo CHAR(1 BYTE), 
	fecha_fin_contrato DATE NOT NULL,
    id_rol NUMBER NOT NULL
);

ALTER TABLE EMPLEADO ADD CONSTRAINT EMPLEADO_PK PRIMARY KEY ( ID_EMPLEADO );



COMMENT ON COLUMN EMPLEADO.ID_EMPLEADO IS 'Identificador de empleado';
COMMENT ON COLUMN EMPLEADO.NOMBRE IS 'Nombre del empleado';
COMMENT ON COLUMN EMPLEADO.APE_PATERNO IS 'Apellido paterno del empleado';
COMMENT ON COLUMN EMPLEADO.APE_MATERNO IS 'Apellido materno del empleado';
COMMENT ON COLUMN EMPLEADO.ACTIVO IS 'Indicador si el empleado esta activo o no: Si(S) o No(N)';
COMMENT ON COLUMN EMPLEADO.FECHA_FIN_CONTRATO IS 'fecha en que termina el contrato del empleado';
COMMENT ON COLUMN EMPLEADO.ID_ROL IS 'identificador del rol del empleado';

ALTER TABLE ORDEN_PRODUCCION ADD CONSTRAINT ORD_PROD_EMPLEADO_FK FOREIGN KEY ( ID_PERSONAL_ACARGO )
REFERENCES  EMPLEADO ( ID_EMPLEADO );


CREATE TABLE ROL(
    id_rol NUMBER NOT NULL,
    descripcion VARCHAR2(50 BYTE) NOT NULL,
    es_jefe CHAR(1 BYTE) NOT NULL, 
	activo CHAR(1 BYTE) NOT NULL
);

ALTER TABLE ROL ADD CONSTRAINT ROL_PK PRIMARY KEY ( ID_ROL );

COMMENT ON COLUMN ROL.ID_ROL IS 'Identificador del rol';
COMMENT ON COLUMN ROL.DESCRIPCION IS 'Descripcion del rol';
COMMENT ON COLUMN ROL.ES_JEFE IS  'Identificador de si el rol es jefe: Si(S) o No(N)';
COMMENT ON COLUMN ROL.ACTIVO IS  'Identificador de si el rol esta activo: Si(S) o No(N)';

ALTER TABLE EMPLEADO ADD(
    CONSTRAINT EMPLEADO_IDROL_FK FOREIGN KEY(ID_ROL) REFERENCES ROL(ID_ROL)
);