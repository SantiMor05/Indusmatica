--Pregunta 1

SELECT ID_MODELO_BUS, MODELO, NUMERO_ASIENTOS, CAPACIDAD_DE_PIE , NUMERO_ASIENTOS + CAPACIDAD_DE_PIE AS CAPACIDAD_TOTAL
FROM ET_MODELO_BUS
ORDER BY CAPACIDAD_TOTAL;


-- Pregunta 2

SELECT t.id_bus, t.fecha, t.sentido, COUNT(*) AS CANTIDAD 
FROM ET_BUS b, ET_TURNO t
WHERE b.id_bus = t.id_bus
GROUP BY t.id_bus, t.sentido,  t.fecha
ORDER BY t.id_bus, t.fecha;


--PRegunta 3

SELECT d.nombre, p.estado, COUNT(*) 
FROM ET_PARADERO p, ET_DISTRITO d
WHERE d.id_distrito = p.id_distrito
GROUP BY d.nombre, p.estado


--Pregunta 4

SELECT t.id_bus, t.fecha, t.id_turno_viaje, t.sentido, SUM(PASAJEROS_SUBIDA)   
FROM ET_TURNO t, ET_TURNO_PARADERO p 
WHERE t.id_turno_viaje = p.id_turno
GROUP BY t.id_turno_viaje,  t.id_bus, t.fecha, t.sentido
ORDER BY t.id_bus, t.sentido;

--Si la fecha fuera con hora;
SELECT TRUNC(t.fecha) FROM dual; --Quitar la hora


--Pregunta 5

--Subquery 
SELECT p.nombre, t.pasajeros_subida, t.pasajeros_bajada, t.pasajeros_subida + t.pasajeros_bajada AS TOTAL_PASAJEROS 
FROM ET_PARADERO p, ET_TURNO_PARADERO t
WHERE p.id_paradero = t.id_paradero
GROUP BY p.nombre, t.pasajeros_subida, t.pasajeros_bajada, t.pasajeros_subida + t.pasajeros_bajada
ORDER BY TOTAL_PASAJEROS DESC, t.pasajeros_subida DESC;

--No se necesita poner el 'p' p.nombre porque ya está incluido dentro del subquery

--Con group by
SELECT nombre, pasajeros_subida, pasajeros_bajada, pasajeros_subida + pasajeros_bajada AS TOTAL_PASAJEROS 
FROM (SELECT p.nombre, t.pasajeros_subida, t.pasajeros_bajada, t.pasajeros_subida + t.pasajeros_bajada AS TOTAL_PASAJEROS 
      FROM ET_PARADERO p, ET_TURNO_PARADERO t
      WHERE p.id_paradero = t.id_paradero
      GROUP BY p.nombre, t.pasajeros_subida, t.pasajeros_bajada, t.pasajeros_subida + t.pasajeros_bajada
      ORDER BY TOTAL_PASAJEROS DESC, t.pasajeros_subida DESC)
where rownum <= 3;

--Con distinct
SELECT nombre, pasajeros_subida, pasajeros_bajada, pasajeros_subida + pasajeros_bajada AS TOTAL_PASAJEROS 
FROM (SELECT DISTINCT p.nombre, t.pasajeros_subida, t.pasajeros_bajada, t.pasajeros_subida + t.pasajeros_bajada AS TOTAL_PASAJEROS 
      FROM ET_PARADERO p, ET_TURNO_PARADERO t
      WHERE p.id_paradero = t.id_paradero
      ORDER BY TOTAL_PASAJEROS DESC, t.pasajeros_subida DESC)
where rownum <= 3;


--Pregunta6

--Subquery
SELECT t.id_turno_viaje, t.sentido, p.nombre, p.tipo 
FROM ET_PARADERO p, ET_TURNO_PARADERO tp, ET_TURNO t
WHERE t.id_turno_viaje = tp.id_turno AND tp.id_paradero = p.id_paradero
ORDER BY t.id_turno_viaje, t.sentido, p.id_paradero, p.tipo

SELECT sentido, nombre, tipo
FROM(SELECT t.id_turno_viaje, t.sentido, p.nombre, p.tipo 
     FROM ET_PARADERO p, ET_TURNO_PARADERO tp, ET_TURNO t
     WHERE t.id_turno_viaje = tp.id_turno AND tp.id_paradero = p.id_paradero
     ORDER BY t.id_turno_viaje, t.sentido, p.id_paradero, p.tipo)
WHERE id_turno_viaje = 120


--Pregunta 7

--Error por orden de ejecucion El order by se ejecuta antes que el select
SELECT c.nombres ||' '|| c.apellido_paterno ||' '|| c.apellido_materno AS CONDUCTOR, COUNT(*) 
FROM ET_CONDUCTOR c, ET_TURNO t
WHERE c.id_conductor = t.id_conductor
GROUP BY CONDUCTOR; 


--Solucion 1
SELECT c.nombres ||' '|| c.apellido_paterno ||' '|| c.apellido_materno AS CONDUCTOR, COUNT(*) 
FROM ET_CONDUCTOR c, ET_TURNO t
WHERE c.id_conductor = t.id_conductor
GROUP BY c.nombres ||' '|| c.apellido_paterno ||' '|| c.apellido_materno;


--Solucion 2
SELECT 
  CONDUCTOR, COUNT(*) 
FROM(
  SELECT c.nombres ||' '|| c.apellido_paterno ||' '|| c.apellido_materno AS CONDUCTOR
  FROM ET_CONDUCTOR c, ET_TURNO t
  WHERE c.id_conductor = t.id_conductor
)
GROUP BY CONDUCTOR;

