--P1
CREATE TABLE BS_CARGO(
    IDCARGO NUMBER NOT NULL,
    DESCRIPCION VARCHAR2(30 BYTE) NOT NULL,
    SUELDO NUMERIC (6,2) NOT NULL,
    IND_TIEMPO_COMPLETO CHAR(1 BYTE) NOT NULL
);

ALTER TABLE BS_CARGO ADD CONSTRAINT PK_BS_CARGO PRIMARY KEY(IDCARGO);

--P2
COMMENT ON COLUMN BS_CARGO.IDCARGO IS 'Identificador del cargo.';
COMMENT ON COLUMN BS_CARGO.DESCRIPCION IS 'Nombre del cargo.';
COMMENT ON COLUMN BS_CARGO.SUELDO IS 'Monto que gana según el cargo.';
COMMENT ON COLUMN BS_CARGO.IND_TIEMPO_COMPLETO
IS 'Indicador si es tiempo completo: Si (S) o No (N)';

--P3
ALTER TABLE BS_EMPLEADO ADD IDCARGO NUMBER NOT NULL;
ALTER TABLE BS_EMPLEADO ADD FECHA_FIN_CONTRATO DATE;
ALTER TABLE BS_TIENDA ADD DIRECCION VARCHAR2(250)NOT NULL;
ALTER TABLE BS_DETALLE_ORDEN ADD COSTO NUMBER(6,2) NOT NULL;

--P4
ALTER TABLE BS_EMPLEADO ADD CONSTRAINT FK_IDCARGO FOREIGN KEY(IDCARGO)
REFERENCES BS_CARGO(IDCARGO);

--P5
ALTER TABLE BS_PERSONA MODIFY PRIMERAPELLIDO VARCHAR2(50);
ALTER TABLE BS_PERSONA MODIFY SEGUNDOAPELLIDO VARCHAR2(50);

--P6
ALTER TABLE BS_GUIASASTRERIA MODIFY IDCLIENTE CHAR(6);

ALTER TABLE BS_GUIASASTRERIA ADD CONSTRAINT FK_IDCLIENTE
FOREIGN KEY(IDCLIENTE) REFERENCES BS_CLIENTE(IDCLIENTE);

--P7
INSERT INTO BS_CARGO VALUES(1,'Administrador',3500,'S');
INSERT INTO BS_CARGO VALUES(2,'Vendedor',3000,'S');
INSERT INTO BS_CARGO VALUES(3,'Sastre',2500,'N');
INSERT INTO BS_CARGO VALUES(4,'Asistente',2700,'S');

--P8
INSERT INTO BS_CATEGORIA(IDCATEGORIA,descripcion)
VALUES(10,'Uniformes');
INSERT INTO BS_CATEGORIA(IDCATEGORIA,descripcion)
VALUES(11,'Abrigos');

SELECT * FROM BS_CATEGORIA;
SELECT * FROM BS_PRENDA;
--P9
DELETE FROM BS_PRENDA
WHERE (bs_prenda.idcategoria>='006' AND bs_prenda.idcategoria<='009')
OR bs_prenda.idcategoria='003';
--REVISANDO LA TABLA DE BS_PRENDA, BASTABA CON ELIMINAR LAS FILAS DE IDCATEGORIA=3

DELETE FROM BS_CATEGORIA
WHERE ESTADO='I';

--P10

SELECT * FROM BS_CLIENTE;
SELECT * FROM BS_PERSONA;

DELETE FROM BS_PERSONA
WHERE IDPERSONA LIKE 'CLI%' AND bs_persona.fechanacimiento IS NULL;

--P11
SELECT * FROM BS_PERSONA
WHERE UPPER(bs_persona.primerapellido) LIKE '%DE%' OR 
UPPER(bs_persona.segundoapellido) LIKE '%DE%' OR SEGUNDOAPELLIDO IS NULL;

SELECT * FROM BS_PRENDA;
SELECT * FROM BS_CATEGORIA
WHERE DESCRIPCION='Moda casual';

SELECT DESCRIPCION FROM BS_PRENDA
WHERE IDCATEGORIA='001' AND COLOR='negro';

