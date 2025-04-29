CREATE TABLE bs_categoria (
    idcategoria  CHAR(3 BYTE) NOT NULL,
    descripcion  VARCHAR2(30 BYTE) NOT NULL,
    estado       CHAR(1 BYTE)
);

COMMENT ON COLUMN bs_categoria.idcategoria IS
    'identificador de la categoria';

COMMENT ON COLUMN bs_categoria.descripcion IS
    'Descripción de la categoría';

COMMENT ON COLUMN bs_categoria.estado IS
    'estado de la categoria: Activo (A) / Inactivo (I)';

ALTER TABLE bs_categoria ADD CONSTRAINT bs_categoria_pk PRIMARY KEY ( idcategoria );

CREATE TABLE bs_cliente (
    idcliente     CHAR(6 BYTE) NOT NULL,
    fechacliente  DATE NOT NULL
);

COMMENT ON COLUMN bs_cliente.idcliente IS
    'identificador de cliente';

COMMENT ON COLUMN bs_cliente.fechacliente IS
    'fecha de la primera compra';

ALTER TABLE bs_cliente ADD CONSTRAINT bs_cliente_pk PRIMARY KEY ( idcliente );

CREATE TABLE bs_detalle_guia (
    idguiapreventa  NUMBER(10) NOT NULL,
    iddetalleguia   NUMBER(3) NOT NULL,
    cantidad        NUMBER(2),
    ind_sastreria   CHAR(1 BYTE) NOT NULL,
    idtienda        NUMBER(3),
    idmatriz        NUMBER(5) NOT NULL,
    idprenda        NUMBER(4) NOT NULL
);

COMMENT ON COLUMN bs_detalle_guia.idguiapreventa IS
    'identificador de la guia';

COMMENT ON COLUMN bs_detalle_guia.iddetalleguia IS
    'identificador del detalle de la guia';

COMMENT ON COLUMN bs_detalle_guia.cantidad IS
    'cantidad de prendas por color';

COMMENT ON COLUMN bs_detalle_guia.ind_sastreria IS
    'indicador si la prenda irá a sastreria: Si (S) o No (N)';

COMMENT ON COLUMN bs_detalle_guia.idtienda IS
    'identificador de la tienda';

COMMENT ON COLUMN bs_detalle_guia.idmatriz IS
    'identificador de la matriz';

COMMENT ON COLUMN bs_detalle_guia.idprenda IS
    'identificador de la prenda';

ALTER TABLE bs_detalle_guia ADD CONSTRAINT bs_detalle_guia_pk PRIMARY KEY ( iddetalleguia,
                                                                            idguiapreventa );

CREATE TABLE bs_detalle_orden (
    idorden         NUMBER(8) NOT NULL,
    idguiapreventa  NUMBER(10) NOT NULL,
    idinventario    NUMBER(5) NOT NULL,
    idtienda        NUMBER(3) NOT NULL
);

COMMENT ON COLUMN bs_detalle_orden.idorden IS
    'Codigo de la orden de fabricacion';

COMMENT ON COLUMN bs_detalle_orden.idguiapreventa IS
    'Identificador del detalle de la orden';

COMMENT ON COLUMN bs_detalle_orden.idinventario IS
    'identificador del inventario';

COMMENT ON COLUMN bs_detalle_orden.idtienda IS
    'identificador de la tienda';

ALTER TABLE bs_detalle_orden ADD CONSTRAINT bs_detalle_orden_pk PRIMARY KEY ( idorden,
                                                                              idguiapreventa );

CREATE TABLE bs_detalle_venta (
    idventa           NUMBER(10) NOT NULL,
    iddetalleventa    NUMBER(3) NOT NULL,
    costo_individual  NUMBER(6, 2) NOT NULL
);

COMMENT ON COLUMN bs_detalle_venta.idventa IS
    'identificador de la venta';

COMMENT ON COLUMN bs_detalle_venta.iddetalleventa IS
    'identificador del detalle de venta';

COMMENT ON COLUMN bs_detalle_venta.costo_individual IS
    'costo de la prenda';

ALTER TABLE bs_detalle_venta ADD CONSTRAINT bs_detalle_venta_pk PRIMARY KEY ( idventa,
                                                                              iddetalleventa );

CREATE TABLE bs_empleado (
    idpersona              CHAR(6 BYTE) NOT NULL,
    idtienda               NUMBER(3) NOT NULL,
    fecha_inicio_contrato  DATE NOT NULL
);

COMMENT ON COLUMN bs_empleado.idpersona IS
    'identificador del empleado';

COMMENT ON COLUMN bs_empleado.fecha_inicio_contrato IS
    'Fecha de inicio del contrato';

ALTER TABLE bs_empleado ADD CONSTRAINT bs_empleado_pk PRIMARY KEY ( idpersona );

CREATE TABLE bs_guiapreventa (
    idguiapreventa  NUMBER(10) NOT NULL,
    fechacreacion   DATE NOT NULL,
    idtienda        NUMBER(3) NOT NULL,
    idempleado      CHAR(6 BYTE) NOT NULL,
    idcliente       NUMBER(8) NOT NULL,
    estado          CHAR(1 BYTE),
    montototal      NUMBER(6, 2) NOT NULL
);

COMMENT ON COLUMN bs_guiapreventa.fechacreacion IS
    'fecha de creacion de la guia de preventa';

COMMENT ON COLUMN bs_guiapreventa.idtienda IS
    'identificador de la tienda';

COMMENT ON COLUMN bs_guiapreventa.idempleado IS
    'identificador del empleado que crea la guia';

COMMENT ON COLUMN bs_guiapreventa.idcliente IS
    'identificador del cliente';

COMMENT ON COLUMN bs_guiapreventa.estado IS
    'estado de la guia: Generada (G) / Procesada (P) / Anulada (3)';

COMMENT ON COLUMN bs_guiapreventa.montototal IS
    'monto total a pagar por el cliente';

ALTER TABLE bs_guiapreventa ADD CONSTRAINT bs_guiapreventa_pk PRIMARY KEY ( idguiapreventa );

CREATE TABLE bs_guiasastreria (
    idguiasastreria        NUMBER(10) NOT NULL,
    idcliente              NUMBER(8) NOT NULL,
    fecharecojo_estimada   DATE NOT NULL,
    fecharecojo_real       DATE,
    idventa                NUMBER(10) NOT NULL,
    montomultaxprendaxdia  NUMBER(4, 2) NOT NULL
);

COMMENT ON COLUMN bs_guiasastreria.idguiasastreria IS
    'identificador de la guia de sastreria';

COMMENT ON COLUMN bs_guiasastreria.idcliente IS
    'identificador del cliente';

COMMENT ON COLUMN bs_guiasastreria.fecharecojo_estimada IS
    'fecha de recojo acordada';

COMMENT ON COLUMN bs_guiasastreria.fecharecojo_real IS
    'fecha de recojo real';

COMMENT ON COLUMN bs_guiasastreria.idventa IS
    'identificador de la venta';

COMMENT ON COLUMN bs_guiasastreria.montomultaxprendaxdia IS
    'monto de la multa por prenda por dia por recoger despues de la fecha estimada';

ALTER TABLE bs_guiasastreria ADD CONSTRAINT bs_guiasastreria_pk PRIMARY KEY ( idguiasastreria );

CREATE TABLE bs_inventario (
    idinventario  NUMBER(5) NOT NULL,
    idtienda      NUMBER(3) NOT NULL,
    idmatriz      NUMBER(5) NOT NULL,
    idprenda      NUMBER(4) NOT NULL,
    stock         NUMBER(2) NOT NULL
);

COMMENT ON COLUMN bs_inventario.idinventario IS
    'identificador del inventario';

COMMENT ON COLUMN bs_inventario.idtienda IS
    'identificador de la tienda';

COMMENT ON COLUMN bs_inventario.idmatriz IS
    'identificador de la matriz';

COMMENT ON COLUMN bs_inventario.idprenda IS
    'identificador de la prenda';

COMMENT ON COLUMN bs_inventario.stock IS
    'cantidad en stock por prenda';

ALTER TABLE bs_inventario ADD CONSTRAINT bs_inventario_pk PRIMARY KEY ( idinventario,
                                                                        idtienda );

CREATE TABLE bs_matriz_talla (
    idmatriz      NUMBER(5) NOT NULL,
    idprenda      NUMBER(4) NOT NULL,
    talla         CHAR(4 BYTE) NOT NULL,
    precio_venta  NUMBER(5, 2) NOT NULL
);

COMMENT ON COLUMN bs_matriz_talla.idmatriz IS
    'identificador de la matriz de tallas';

COMMENT ON COLUMN bs_matriz_talla.idprenda IS
    'identificador de la prenda';

COMMENT ON COLUMN bs_matriz_talla.talla IS
    'talla: XS / S / M / L / XL / XXL / XXXL';

COMMENT ON COLUMN bs_matriz_talla.precio_venta IS
    'precio de venta de la prenda';

ALTER TABLE bs_matriz_talla ADD CONSTRAINT bs_matriz_talla_pk PRIMARY KEY ( idmatriz,
                                                                            idprenda );

CREATE TABLE bs_orden_fabricacion (
    idorden                 NUMBER(8) NOT NULL,
    fecha_creacion          DATE,
    idempleado              CHAR(6 BYTE) NOT NULL,
    fecha_entrega_estimada  DATE,
    fecha_entrega_real      DATE,
    costo_total             NUMBER(8, 2) NOT NULL
);

COMMENT ON COLUMN bs_orden_fabricacion.idorden IS
    'Identificador de la orden';

COMMENT ON COLUMN bs_orden_fabricacion.fecha_creacion IS
    'fecha en que se registra la orden de fabricacion';

COMMENT ON COLUMN bs_orden_fabricacion.idempleado IS
    'codigo del encargado que creo la orden';

COMMENT ON COLUMN bs_orden_fabricacion.fecha_entrega_estimada IS
    'fecha de entrega estimada';

COMMENT ON COLUMN bs_orden_fabricacion.fecha_entrega_real IS
    'fecha de entrega real';

COMMENT ON COLUMN bs_orden_fabricacion.costo_total IS
    'costo total de fabricación';

ALTER TABLE bs_orden_fabricacion ADD CONSTRAINT bs_orden_fabricacion_pk PRIMARY KEY ( idorden );

CREATE TABLE bs_persona (
    idpersona        CHAR(6 BYTE) NOT NULL,
    docidentidad     NUMBER(12) NOT NULL,
    nombres          VARCHAR2(10 BYTE) NOT NULL,
    primerapellido   VARCHAR2(20 BYTE) NOT NULL,
    segundoapellido  VARCHAR2(20 BYTE),
    fechanacimiento  DATE,
    celular          NUMBER(9) NOT NULL
);

COMMENT ON COLUMN bs_persona.idpersona IS
    'identificador de la persona';

COMMENT ON COLUMN bs_persona.docidentidad IS
    'Numero de documento de identidad';

COMMENT ON COLUMN bs_persona.nombres IS
    'nombres';

COMMENT ON COLUMN bs_persona.primerapellido IS
    'Apellido paterno';

COMMENT ON COLUMN bs_persona.segundoapellido IS
    'Apellido materno';

COMMENT ON COLUMN bs_persona.fechanacimiento IS
    'fecha de nacimiento';

COMMENT ON COLUMN bs_persona.celular IS
    'celular de la persona';

ALTER TABLE bs_persona ADD CONSTRAINT bs_persona_pk PRIMARY KEY ( idpersona );

CREATE TABLE bs_prenda (
    idprenda     NUMBER(4) NOT NULL,
    idcategoria  CHAR(3 BYTE) NOT NULL,
    descripcion  VARCHAR2(50 BYTE),
    color        VARCHAR2(20 BYTE) NOT NULL
);

COMMENT ON COLUMN bs_prenda.idprenda IS
    'Código de la prenda';

COMMENT ON COLUMN bs_prenda.idcategoria IS
    'identificador de Categoria';

COMMENT ON COLUMN bs_prenda.descripcion IS
    'Descripción de la prenda';

COMMENT ON COLUMN bs_prenda.color IS
    'color de la prenda';

ALTER TABLE bs_prenda ADD CONSTRAINT bs_prenda_pk PRIMARY KEY ( idprenda );

CREATE TABLE bs_tienda (
    idtienda       NUMBER(3) NOT NULL,
    fechaapertura  DATE
);

COMMENT ON COLUMN bs_tienda.idtienda IS
    'identificador de la tienda';

COMMENT ON COLUMN bs_tienda.fechaapertura IS
    'fecha de apertura de la tienda';

ALTER TABLE bs_tienda ADD CONSTRAINT bs_tienda_pk PRIMARY KEY ( idtienda );

CREATE TABLE bs_venta (
    idventa           NUMBER(10) NOT NULL,
    idguiapreventa    NUMBER(10) NOT NULL,
    fechaprocesopago  DATE
);

COMMENT ON COLUMN bs_venta.idventa IS
    'identificador de la venta';

COMMENT ON COLUMN bs_venta.fechaprocesopago IS
    'fecha que se procesa el pago';

ALTER TABLE bs_venta ADD CONSTRAINT bs_venta_pk PRIMARY KEY ( idventa );

ALTER TABLE bs_cliente
    ADD CONSTRAINT bs_cliente_bs_persona_fk FOREIGN KEY ( idcliente )
        REFERENCES bs_persona ( idpersona );

ALTER TABLE bs_detalle_guia
    ADD CONSTRAINT bs_det_guia_bs_guiaprevnt_fk FOREIGN KEY ( idguiapreventa )
        REFERENCES bs_guiapreventa ( idguiapreventa );

ALTER TABLE bs_detalle_guia
    ADD CONSTRAINT bs_det_guia_bs_matriz_fk FOREIGN KEY ( idmatriz,
                                                          idprenda )
        REFERENCES bs_matriz_talla ( idmatriz,
                                     idprenda );

ALTER TABLE bs_detalle_orden
    ADD CONSTRAINT bs_det_orden_bs_inv_fk FOREIGN KEY ( idinventario,
                                                        idtienda )
        REFERENCES bs_inventario ( idinventario,
                                   idtienda );

ALTER TABLE bs_detalle_orden
    ADD CONSTRAINT bs_det_orden_bs_ord_fab_fk FOREIGN KEY ( idorden )
        REFERENCES bs_orden_fabricacion ( idorden );

ALTER TABLE bs_detalle_venta
    ADD CONSTRAINT bs_detalle_venta_bs_venta_fk FOREIGN KEY ( idventa )
        REFERENCES bs_venta ( idventa );

ALTER TABLE bs_empleado
    ADD CONSTRAINT bs_empleado_bs_persona_fk FOREIGN KEY ( idpersona )
        REFERENCES bs_persona ( idpersona );

ALTER TABLE bs_empleado
    ADD CONSTRAINT bs_empleado_bs_tienda_fk FOREIGN KEY ( idtienda )
        REFERENCES bs_tienda ( idtienda );

ALTER TABLE bs_guiapreventa
    ADD CONSTRAINT bs_guiapreventa_bs_empleado_fk FOREIGN KEY ( idempleado )
        REFERENCES bs_empleado ( idpersona );

ALTER TABLE bs_guiapreventa
    ADD CONSTRAINT bs_guiapreventa_bs_tienda_fk FOREIGN KEY ( idtienda )
        REFERENCES bs_tienda ( idtienda );

ALTER TABLE bs_guiasastreria
    ADD CONSTRAINT bs_guiasastreria_bs_venta_fk FOREIGN KEY ( idventa )
        REFERENCES bs_venta ( idventa );

ALTER TABLE bs_inventario
    ADD CONSTRAINT bs_inventario_bs_matriz_fk FOREIGN KEY ( idmatriz,
                                                            idtienda )
        REFERENCES bs_matriz_talla ( idmatriz,
                                     idprenda );

ALTER TABLE bs_inventario
    ADD CONSTRAINT bs_inventario_bs_prenda_fk FOREIGN KEY ( idtienda )
        REFERENCES bs_tienda ( idtienda );

ALTER TABLE bs_matriz_talla
    ADD CONSTRAINT bs_matriz_talla_bs_prenda_fk FOREIGN KEY ( idprenda )
        REFERENCES bs_prenda ( idprenda );

ALTER TABLE bs_orden_fabricacion
    ADD CONSTRAINT bs_orden_fab_bs_empleado_fk FOREIGN KEY ( idempleado )
        REFERENCES bs_empleado ( idpersona );

ALTER TABLE bs_prenda
    ADD CONSTRAINT bs_prenda_bs_categoria_fk FOREIGN KEY ( idcategoria )
        REFERENCES bs_categoria ( idcategoria );

ALTER TABLE bs_venta
    ADD CONSTRAINT bs_venta_bs_guiapreventa_fk FOREIGN KEY ( idguiapreventa )
        REFERENCES bs_guiapreventa ( idguiapreventa );