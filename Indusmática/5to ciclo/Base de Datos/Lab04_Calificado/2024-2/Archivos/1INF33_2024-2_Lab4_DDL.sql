

CREATE TABLE CLIENTE (
    id_cliente       CHAR(10 BYTE) NOT NULL,
    razon_social     CHAR(80 BYTE),
    ruc              CHAR(11 BYTE),
    telefono         CHAR(11 BYTE),
    correo           CHAR(50 BYTE),
    direccion_fiscal CHAR(120 BYTE)
)
;

COMMENT ON COLUMN CLIENTE.id_cliente IS
    'identificador del cliente.';

COMMENT ON COLUMN CLIENTE.razon_social IS
    'razon social del cliente.';

COMMENT ON COLUMN CLIENTE.ruc IS
    'ruc del cliente.';

ALTER TABLE CLIENTE
    ADD CONSTRAINT cliente_pk PRIMARY KEY ( id_cliente );
	
	
CREATE TABLE TIPO_BUS (
    id_tipo_bus CHAR(10 BYTE) NOT NULL,
    nombre      CHAR(120 BYTE)
)
;

COMMENT ON COLUMN TIPO_BUS.id_tipo_bus IS
    'identificador del tipo de bus';

COMMENT ON COLUMN TIPO_BUS.nombre IS
    'nombre comercial del tipo de bus';

ALTER TABLE TIPO_BUS
    ADD CONSTRAINT tipo_bus_pk PRIMARY KEY ( id_tipo_bus )
;

	
CREATE TABLE DETALLE_ORD_PEDIDO (
    id_detalle_pedido     CHAR(10 BYTE) NOT NULL,
    id_orden_pedido       CHAR(10 BYTE) NOT NULL,
    cantidad              NUMBER,
    en_stock              CHAR(1 BYTE),
    id_orden_produccion   CHAR(10 BYTE),
    id_tipo_bus           CHAR(10 BYTE) NOT NULL,
    precio_venta_unitario FLOAT(126)
)
;

COMMENT ON COLUMN DETALLE_ORD_PEDIDO.cantidad IS
    'cantidad del pedido.';

COMMENT ON COLUMN DETALLE_ORD_PEDIDO.en_stock IS
    'indicador de si hay stock o no.';

ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT detalle_ord_pedido_pk PRIMARY KEY ( id_detalle_pedido );

CREATE TABLE EMPLEADO (
    id_empleado        NUMBER NOT NULL,
    nombre             VARCHAR2(40 BYTE),
    ape_paterno        VARCHAR2(40 BYTE),
    ape_materno        VARCHAR2(40 BYTE),
    activo             CHAR(1 BYTE),
    fecha_fin_contrato DATE NOT NULL,
    id_rol             NUMBER NOT NULL
)
;

COMMENT ON COLUMN EMPLEADO.id_empleado IS
    'Identificador de empleado';

COMMENT ON COLUMN EMPLEADO.nombre IS
    'Nombre del empleado';

COMMENT ON COLUMN EMPLEADO.ape_paterno IS
    'Apellido paterno del empleado';

COMMENT ON COLUMN EMPLEADO.ape_materno IS
    'Apellido materno del empleado';

COMMENT ON COLUMN EMPLEADO.activo IS
    'Indicador si el empleado esta activo o no: Si(S) o No(N)';

COMMENT ON COLUMN EMPLEADO.fecha_fin_contrato IS
    'fecha en que termina el contrato del empleado';

COMMENT ON COLUMN EMPLEADO.id_rol IS
    'identificador del rol del empleado';

ALTER TABLE EMPLEADO
    ADD CONSTRAINT empleado_pk PRIMARY KEY ( id_empleado )
;

CREATE TABLE FORMA_PAGO (
    id_forma_pago     CHAR(10 BYTE) NOT NULL,
    nombre_forma_pago CHAR(120 BYTE),
    moneda            CHAR(4 BYTE)
)
;

COMMENT ON COLUMN FORMA_PAGO.id_forma_pago IS
    'identificador de la forma de pago.';

COMMENT ON COLUMN FORMA_PAGO.nombre_forma_pago IS
    'descripcion de la forma de pago.';

COMMENT ON COLUMN FORMA_PAGO.moneda IS
    'indicador de la moneda de la forma de pago.';

ALTER TABLE FORMA_PAGO
    ADD CONSTRAINT forma_pago_pk PRIMARY KEY ( id_forma_pago )
;

CREATE TABLE ORDEN_PEDIDO (
    id_orden_pedido CHAR(10 BYTE) NOT NULL,
    fecha_registro  DATE,
    fecha_entrega   DATE,
    id_cliente      CHAR(10 BYTE) NOT NULL,
    id_sede         CHAR(10 BYTE) NOT NULL,
    id_forma_pago   CHAR(10 BYTE) NOT NULL
)
;

ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT orden_pedido_pk PRIMARY KEY ( id_orden_pedido )
;

CREATE TABLE ORDEN_PRODUCCION (
    id_orden_produccion       CHAR(10 BYTE) NOT NULL,
    fecha_registro            DATE,
    fecha_inicio              DATE NOT NULL,
    fecha_culminacion         DATE,
    id_personal_acargo        NUMBER NOT NULL,
    especificacion            CHAR(200 BYTE),
    costo_produccion_unitario FLOAT(126)
)
;

ALTER TABLE ORDEN_PRODUCCION
    ADD CONSTRAINT orden_produccion_pk PRIMARY KEY ( id_orden_produccion )
;

CREATE TABLE ROL (
    id_rol      NUMBER NOT NULL,
    descripcion VARCHAR2(50 BYTE) NOT NULL,
    es_jefe     CHAR(1 BYTE) NOT NULL,
    activo      CHAR(1 BYTE) NOT NULL
)
;

COMMENT ON COLUMN ROL.id_rol IS
    'Identificador del rol';

COMMENT ON COLUMN ROL.descripcion IS
    'Descripcion del rol';

COMMENT ON COLUMN ROL.es_jefe IS
    'Identificador de si el rol es jefe: Si(S) o No(N)';

COMMENT ON COLUMN ROL.activo IS
    'Identificador de si el rol esta activo: Si(S) o No(N)';

ALTER TABLE ROL
    ADD CONSTRAINT rol_pk PRIMARY KEY ( id_rol )
;

CREATE TABLE SEDE (
    id_sede                   CHAR(10 BYTE) NOT NULL,
    nombre_sede               CHAR(150 BYTE),
    distrito                  CHAR(20 BYTE),
    provincia                 CHAR(50 BYTE),
    area_sede                 NUMBER,
    direccion                 CHAR(120 BYTE),
    telefono                  CHAR(11 CHAR),
    codigo_postal             VARCHAR2(6 BYTE),
    activo                    CHAR(1 BYTE),
    fecha_creacion            DATE,
    fecha_ultima_modificacion DATE
)
;

COMMENT ON COLUMN SEDE.id_sede IS
    'identificador de la sede';

COMMENT ON COLUMN SEDE.nombre_sede IS
    'nombre de la sede';

COMMENT ON COLUMN SEDE.distrito IS
    'nombre del distrito';

COMMENT ON COLUMN SEDE.provincia IS
    'nombre de la provincia';

COMMENT ON COLUMN SEDE.area_sede IS
    'nombre del area en la sede';

COMMENT ON COLUMN SEDE.direccion IS
    'direccion fisica de la sede';

COMMENT ON COLUMN SEDE.telefono IS
    'telefono principal de la seda';

COMMENT ON COLUMN SEDE.codigo_postal IS
    'codigo postal de la sede';

COMMENT ON COLUMN SEDE.activo IS
    'Identificador de si la sede esta activa: Si(S) o No(N)';

ALTER TABLE SEDE
    ADD CONSTRAINT sede_pk PRIMARY KEY ( id_sede )
;


ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT detordpedido_ordenpedido_fk
        FOREIGN KEY ( id_orden_pedido )
            REFERENCES orden_pedido ( id_orden_pedido )
            NOT DEFERRABLE;

ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT detordpedido_ordprod_fk
        FOREIGN KEY ( id_orden_produccion )
            REFERENCES orden_produccion ( id_orden_produccion )
            NOT DEFERRABLE;

ALTER TABLE DETALLE_ORD_PEDIDO
    ADD CONSTRAINT detordpedido_tipobus_fk
        FOREIGN KEY ( id_tipo_bus )
            REFERENCES tipo_bus ( id_tipo_bus )
            NOT DEFERRABLE;

ALTER TABLE EMPLEADO
    ADD CONSTRAINT empleado_idrol_fk
        FOREIGN KEY ( id_rol )
            REFERENCES rol ( id_rol )
            NOT DEFERRABLE;

ALTER TABLE ORDEN_PRODUCCION
    ADD CONSTRAINT ord_prod_empleado_fk
        FOREIGN KEY ( id_personal_acargo )
            REFERENCES empleado ( id_empleado )
            NOT DEFERRABLE;

ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT orden_pedido_cliente_fk
        FOREIGN KEY ( id_cliente )
            REFERENCES cliente ( id_cliente )
            NOT DEFERRABLE;

ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT orden_pedido_forma_pago_fk
        FOREIGN KEY ( id_forma_pago )
            REFERENCES forma_pago ( id_forma_pago )
            NOT DEFERRABLE;

ALTER TABLE ORDEN_PEDIDO
    ADD CONSTRAINT orden_pedido_sede_fk
        FOREIGN KEY ( id_sede )
            REFERENCES sede ( id_sede )
            NOT DEFERRABLE;




