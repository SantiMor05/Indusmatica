--PREGUNTA 1
CREATE OR REPLACE FUNCTION FN_TOTAL_BUSES_TIPO(P_ID_TIPO_BUS CHAR)
RETURN NUMBER
IS
    V_TOTAL NUMBER;
BEGIN
    SELECT NVL(SUM(CANTIDAD),0)
    INTO V_TOTAL
    FROM DETALLE_ORD_PEDIDO
    WHERE ID_TIPO_BUS = P_ID_TIPO_BUS;

    RETURN V_TOTAL;
END FN_TOTAL_BUSES_TIPO;

SELECT fn_total_buses_tipo(1) FROM dual;
SELECT fn_total_buses_tipo(5) FROM dual;
SELECT fn_total_buses_tipo(999) FROM dual;


--PREGUNTA 2

CREATE OR REPLACE FUNCTION fn_eficiencia_entrega_sede (p_id_sede char)
return number
is 
    v_ord_total number;
    v_ord_cumple number;
    v_ord_prom number;
begin
    select count(*)
    into v_ord_total
    from orden_pedido
    where id_sede=p_id_sede
    and fecha_entrega is not null
    and fecha_registro is not null
    ;
    
    if v_ord_total=0 then
        return 0;
    end if;
    
    select count(*)
    into v_ord_cumple
    from orden_pedido
    where id_sede=p_id_sede
    and fecha_entrega is not null
    and fecha_registro is not null
    and (fecha_entrega - fecha_registro)<= 30
    ;
    
    v_ord_prom :=round( v_ord_cumple/v_ord_total *100,0);
    
    return v_ord_prom;
    
end;

select * from orden_pedido
where id_sede=1
;

select fn_eficiencia_entrega_sede(1) from dual; 

-------------------------------------------------------------------
--Profe Cueva
CREATE OR REPLACE FUNCTION fn_eficiencia_entrega_sede(p_id_sede char,
    p_num_dias number)
return number
is
    v_ord_total NUMBER;    
    v_ord_valida NUMBER;
BEGIN
    SELECT COUNT(*)
        into v_ord_total
    FROM orden_pedido
    WHERE id_sede = p_id_sede
    AND fecha_registro is not NULL
    AND fecha_entrega IS NOT NULL;
    
    IF v_ord_total=0 then
        return 0;
    end if;

    SELECT COUNT(*)
        into v_ord_valida
    FROM orden_pedido
    WHERE id_sede = p_id_sede
    AND fecha_registro is not NULL
    AND fecha_entrega IS NOT NULL
    AND (fecha_entrega-fecha_registro)<=p_num_dias;
    
    return round((v_ord_valida/v_ord_total)*100,0);
    
END;

SELECT fn_eficiencia_entrega_sede(1,20) FROM DUAL;

-- PREGUNTA 3

set SERVEROUTPUT on;

CREATE OR REPLACE PROCEDURE sp_registrar_cliente (p_id_cliente char,
    p_razon_social char,
    p_ruc char,
    p_telefono char,
    p_correo char,
    p_direccion_fiscal char)
as
    v_cliente_existe number;
    v_encontro_error  boolean;
begin
    v_encontro_error:=false;
    
    select count(*) into v_cliente_existe
    from CLIENTE
    where id_cliente = p_id_cliente
    ;
    --ID CLIENTE
    if(v_cliente_existe != 0) then
        dbms_output.put_line('Error: El ID de cliente ' || p_id_cliente || ' ya existe.');
        v_encontro_error := true;
    end if;
    
    --RAZON SOCIAL
    if p_razon_social is null then
        dbms_output.put_line('Error: La razón social es obligatoria');
        v_encontro_error := true;
    end if;
    
    --RUC
    if p_ruc is null then
        dbms_output.put_line('Error: El RUC es obligatoria');
        v_encontro_error := true;
    end if;
    
     if p_telefono is null then
        dbms_output.put_line('Error: El telefono es obligatoria');
        v_encontro_error := true;
    end if;
    
     if p_correo is null then
        dbms_output.put_line('Error: El correo es obligatoria');
        v_encontro_error := true;
    end if;
    
    if v_encontro_error=false then
        insert into cliente(ID_CLIENTE,razon_social,RUC,TELEFONO,CORREO,DIRECCION_FISCAL) 
        values(p_id_cliente,p_razon_social, p_ruc,p_telefono,p_correo, p_direccion_fiscal);
        dbms_output.put_line('Cliente registrado exitosamente');
    end if;
    
end;

EXEC sp_registrar_cliente(12, 'Transportes Express', '20505050505', '998877665', 'contact@express.com', 'Av. Principal 123');
EXEC sp_registrar_cliente(10, NULL, NULL, NULL, NULL, NULL);
EXEC sp_registrar_cliente(11, '', '', '', '', '');
EXEC sp_registrar_cliente(1, 'Nueva Empresa', '20606060606', '999999999', 'info@nueva.com', 'Calle Nueva 789');


--Pregunta 4

set SERVEROUTPUT on;

CREATE OR REPLACE PROCEDURE sp_cliente_mas_pedidos(p_anho number)
as
    v_existe number;
    v_cant_pedidos number;
    v_id_cliente_mayor_ped number;
begin
    if(EXTRACT(YEAR FROM sysdate)<p_anho) then
        dbms_output.put_line('Error: el año no puede ser del futuro');
        return;
    end if;

    select count(*) into v_existe
    from orden_pedido
    where EXTRACT(YEAR FROM fecha_registro)=p_anho;
    
    if(v_existe=0) then
        dbms_output.put_line('No se encontraron pedidos en el año '||p_anho);
        return;
    --else
    --    dbms_output.put_line('Se encontraron pedidos en el año '||p_anho);
    end if;
    
    select max(count(*)) into v_cant_pedidos
    from orden_pedido
    where  EXTRACT(YEAR FROM fecha_registro)= p_anho
    GROUP BY ID_CLIENTE;
    
    select id_cliente into v_id_cliente_mayor_ped
    from orden_pedido
    where  EXTRACT(YEAR FROM fecha_registro)= p_anho
    GROUP BY ID_CLIENTE
    having count(*)= v_cant_pedidos
    ;
    
    dbms_output.put_line('Cliente con más pedidos en '||p_anho);
    dbms_output.put_line('ID Cliente:  '||v_id_cliente_mayor_ped);
    dbms_output.put_line('Cantidad de pedidos:  '||v_cant_pedidos);
end;

EXEC sp_cliente_mas_pedidos(2024);