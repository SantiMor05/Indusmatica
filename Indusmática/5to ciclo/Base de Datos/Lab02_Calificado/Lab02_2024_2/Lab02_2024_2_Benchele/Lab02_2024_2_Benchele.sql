-- Pregunta 1

SELECT UPPER(NOMBRE) ||' '|| UPPER(APE_PATERNO) ||' '|| UPPER(APE_MATERNO) AS NOMBRE_COMPLETO, FECHA_FIN_CONTRATO
FROM EMPLEADO
--WHERE FECHA_FIN_CONTRATO <= ADD_MONTHS(SYSDATE, 6)
WHERE FECHA_FIN_CONTRATO <= ADD_MONTHS('07/10/2024', 6)
--AND FECHA_FIN_CONTRATO >= SYSDATE
AND ACTIVO = 'S' --En la imagen se muestra tambien a los que no son activos, pero es solo "activos"
ORDER BY FECHA_FIN_CONTRATO DESC;


-- Pregunta 2

SELECT ID_ORDEN_PRODUCCION, FECHA_CULMINACION, 
       ROUND(MONTHS_BETWEEN('06/10/2024', FECHA_CULMINACION), 2) AS CANTIDAD_MESES
       --ROUND(MONTHS_BETWEEN(SYSDATE, FECHA_CULMINACION), 2)
FROM ORDEN_PRODUCCION
WHERE TO_NUMBER(TO_CHAR(FECHA_CULMINACION, 'YYYY')) = 2024 
AND TO_NUMBER(TO_CHAR(FECHA_CULMINACION, 'MM')) <= 6;


-- Pregunta 3

SELECT ARTICULO, MIN(CANTIDAD), MAX(CANTIDAD)
FROM DETALLE_ORD_PRODUCCION
GROUP BY ARTICULO --Por cada articulo


-- Pregunta 4

--Forma 1 -> SELECT MAX() Al agrupar los ID's de la orden quedan varios nombres y los unificas así
SELECT o.id_sede, max(s.nombre_sede) AS NOMBRE_SEDE, COUNT(*)
FROM SEDE s, ORDEN_PEDIDO o
WHERE s.id_sede = o.id_sede and TO_NUMBER(TO_CHAR(o.fecha_entrega, 'YYYY')) = 2024
GROUP BY o.ID_SEDE;

-- Forma 2 -> GROUP BY s.ID_SEDE, s.nombre_sede, se agrupa por los dos, por cada id en "orden_pedido" un nombre en "sede"
SELECT o.id_sede, s.nombre_sede, COUNT(*)
FROM SEDE s, ORDEN_PEDIDO o
--WHERE s.id_sede = o.id_sede and TO_NUMBER(TO_CHAR(o.fecha_entrega, 'YYYY')) = 2024
WHERE s.id_sede = o.id_sede and TO_NUMBER(TO_CHAR(fecha_entrega, 'YYYY')) = 2024 --Se puede poner si o. || s. porque es comun en ambas tablas
GROUP BY o.ID_SEDE, s.nombre_sede;


--Pregunta 5

--Forma 1
SELECT c.id_cliente, max(c.razon_social)
FROM CLIENTE c, ORDEN_PEDIDO o, DETALLE_ORD_PEDIDO d
WHERE c.id_cliente = o.id_cliente AND o.id_orden_pedido = d.id_orden_pedido
AND d.id_tipo_bus in (1,2)
GROUP BY c.id_cliente
ORDER BY c.id_cliente; --No menciona ordenar

-- Forma 2
SELECT c.id_cliente, c.razon_social
FROM CLIENTE c, ORDEN_PEDIDO o, DETALLE_ORD_PEDIDO d
WHERE c.id_cliente = o.id_cliente AND o.id_orden_pedido = d.id_orden_pedido
AND d.id_tipo_bus in (1,2)
GROUP BY c.id_cliente, c.razon_social
ORDER BY c.id_cliente; --No menciona ordenar


--Pregunta 6

SELECT max(t.nombre), SUM(d.cantidad) AS CANTIDAD 
FROM DETALLE_ORD_PEDIDO d, TIPO_BUS t
WHERE d.id_tipo_bus = t.id_tipo_bus
GROUP BY t.id_tipo_bus
HAVING SUM(d.cantidad) > 40; -- Condicion que debe cumplir la agrupacion


--Pregunta 7

SELECT  f.nombre_forma_pago, SUM(d.cantidad) AS CANTIDAD -- Por cada pedido es un bus -- Es decir si cantidad es 27 y tipo bus 3, Son 27 buses del tipo 3
FROM FORMA_PAGO f, ORDEN_PEDIDO o, DETALLE_ORD_PEDIDO d
WHERE f.id_forma_pago = o.id_forma_pago AND o.id_orden_pedido = d.id_orden_pedido
GROUP BY f.nombre_forma_pago;

