--PREGUNTA 1
set SERVEROUTPUT on;

/

create or REPLACE PROCEDURE sp_mostrar_ventas(p_fecha_ini date,p_fecha_fin date)
as
    cursor ccabecera is 
    select v.venta_id VENTA_ID,c.nombre ||' ' || c.apellido NOMBRE,v.fecha_venta FECHA 
    from l6_ventas v,l6_clientes c
    where v.fecha_venta between p_fecha_ini and p_fecha_fin and
    v.cliente_id=c.cliente_id
    order by FECHA;
    
    cursor cdetalle (pventa_id number) is
    select p.nombre, D.CANTIDAD,d.PRECIO_UNITARIO ,D.PRECIO_FINAL
    from l6_ventas_detalle d, l6_productos p
    where d.venta_id=pventa_id and
    d.producto_id=p.producto_id;
begin
    for rcabecera in ccabecera
    loop
        dbms_output.put_line('Documento de venta: ' || rcabecera.venta_id );
        dbms_output.put_line('Cliente: ' || rcabecera.NOMBRE );
        dbms_output.put_line('Fecha: ' || rcabecera.FECHA);
        dbms_output.put_line('-----------------------------------------------');
        dbms_output.put_line(RPAD('Nombre',40) ||RPAD('Cantidad',20)|| RPAD('Precio Unit.',20) 
        || RPAD('Precio Final',20));
        for rdetalle in cdetalle(rcabecera.venta_id)
        loop    
            dbms_output.put_line(RPAD(rdetalle.nombre,40) ||RPAD(rdetalle.cantidad,20) 
            || RPAD('S/. '||to_char(rdetalle.precio_unitario,'999.00'),20) 
        || RPAD('S/. '||to_char(rdetalle.PRECIO_FINAL,'999.00'),20) );
        end loop;
        dbms_output.put_line('=============================================');
    end loop;
end;

/

exec sp_mostrar_ventas('08/02/24',sysdate);

--Pregunta 2
/
create or replace procedure sp_cliente_de_campanhas
as
    cursor ccampanha is
    select CAMPANIA_ID, NOMBRE
    from l6_campanias;
    
    cursor ccliente(PCAMPANIA_ID number) is
    select c.nombre || ' '  ||c.apellido as nombCompleto
    from l6_ventas_detalle d, l6_ventas v, l6_clientes c
    where d.CAMPANIA_ID=PCAMPANIA_ID AND
    d.venta_id=v.venta_id and v.cliente_id=c.cliente_id
    group by c.nombre || ' '  ||c.apellido
    order by 1;
    
    cursor ccliente_sin is
    select c.nombre || ' '  ||c.apellido as nombCompleto
    from l6_ventas_detalle d, l6_ventas v, l6_clientes c
    where d.CAMPANIA_ID is null AND
    d.venta_id=v.venta_id and v.cliente_id=c.cliente_id
    group by c.nombre || ' '  ||c.apellido;
    
    CURSOR CNCLIENTES IS 
    SELECT max(c.nombre||' '||c.apellido)  nomcompleto
    FROM l6_ventas_detalle d, l6_ventas v, l6_clientes c 
    where v.venta_id = d.venta_id 
    and c.cliente_id = v.cliente_id
    and campania_id is null 
    group by c.nombre||' '||c.apellido; 
    
begin
    for rcampanha in ccampanha
    loop
        dbms_output.put_line('Nombre de la camapania: ' || rcampanha.NOMBRE);
        dbms_output.put_line('-----------------------------------------------');
        for rcliente_con_campania in ccliente(rcampanha.CAMPANIA_ID)
        loop
             dbms_output.put_line(rcliente_con_campania.nombCompleto);
        end loop;
        dbms_output.put_line(' ');
    end loop;
    dbms_output.put_line('Nombre de la camapania: Sin camapaña');
    dbms_output.put_line('-----------------------------------------------');
        
    for rcliente_sin_campania in ccliente_sin
    loop
        dbms_output.put_line(rcliente_sin_campania.nombCompleto);
    end loop;
end;

/

exec sp_cliente_de_campanhas;

/

--Pregunta 3
/
create or replace procedure sp_reporte_productos
as
    CURSOR CPRODUCTOS IS 
    SELECT  PRODUCTO_ID,CODIGO_PRODUCTO, p.NOMBRE,e.nombre editorial 
    FROM l6_PRODUCTOS P, l6_editoriales E 
    WHERE p.editorial_id = e.editorial_id 
    union all
    SELECT  PRODUCTO_ID,CODIGO_PRODUCTO, p.NOMBRE,''
    FROM l6_PRODUCTOS P
    WHERE p.editorial_id IS NULL  
    order by producto_id; 
    
    cursor clibros(pproducto_id number) is
    select ISBN, ANIO_PUBLICACION anho,LIBRO_ID
    from l6_libros
    where PRODUCTO_ID=pproducto_id
    ;
    
    cursor ccursos(plibro_id number) is
    SELECT  codigo,nombre, facultad 
    FROM l6_bibliografia_cursos B, l6_CURSOS C 
    WHERE b.libro_id = plibro_id 
    AND b.curso_id = c.curso_id;
    
begin 
    for rproducto in cproductos
    loop
        dbms_output.put_line('===============================================');
        dbms_output.put_line('Codigo del Producto: ' || rproducto.codigo_producto);
        dbms_output.put_line('Nombre del Producto: ' || rproducto.nombre);
        dbms_output.put_line('-----------------------------------------------');
        dbms_output.put_line('Editorial: ' || NVL(rproducto.editorial,'NO HAY'));
        
        for rlibro in clibros(rproducto.producto_id)
        loop
            dbms_output.put_line('ISBN: '||rlibro.isbn);
            dbms_output.put_line('Anho: '||rlibro.anho);
            dbms_output.put_line('-----------------------------------------------');
            for rcursos in ccursos(rlibro.libro_id)
            loop
                dbms_output.put_line(rcursos.codigo || ' ' || rcursos.nombre);
            end loop;
        end loop;
    end loop;
end;

/

exec sp_reporte_productos;

/

--Pregunta 4

create or replace procedure sp_kardex
as
    cursor cproductos is
    select  PRODUCTO_ID,CODIGO_PRODUCTO,NOMBRE,STOCK_ACTUAL
    from l6_productos;
    
    cursor cmovimientos(PPRODUCTO_ID number) is
    select FECHA_VENTA fecha, CANTIDAD,'Venta' motivo
    from l6_ventas v, l6_ventas_detalle d
    where v.venta_id=d.venta_id 
    and d.producto_id=PPRODUCTO_ID
    union all
    select FECHA_REGISTRO,cantidad,MOTIVO
    from l6_perdidas_inventario
    where producto_id=pPRODUCTO_ID;
    
    suma_venta number;
    suma_perdida number;
    stock_ini number;
begin
    for rproducto in cproductos
    loop
        select nvl(sum(cantidad),0)  into suma_venta
        from l6_ventas_detalle
        where producto_id=rproducto.producto_id;
        
        select nvl(sum(cantidad),0) into suma_perdida
        from l6_perdidas_inventario
        where producto_id=rproducto.producto_id;
        
        stock_ini:=rproducto.stock_actual+suma_perdida+suma_venta;
        
        dbms_output.put_line('Codigo del Producto: '||rproducto.CODIGO_PRODUCTO);
        dbms_output.put_line('Nombre del Producto: '||rproducto.nombre);
        dbms_output.put_line('Stock Inicial: '||stock_ini);
        dbms_output.put_line('-----------------------------------------------');
        dbms_output.put_line('Movimientos:');
        dbms_output.put_line(rpad('Fecha',20)||rpad('Cantidad',20)||rpad('Motivo',20));
       
        
        for rmov in cmovimientos(rproducto.producto_id)
        loop
             dbms_output.put_line(rpad(rmov.fecha,20)||
             rpad(rmov.cantidad,20)||
             rpad(rmov.motivo,20));
        end loop;
        dbms_output.put_line('-----------------------------------------------');
        dbms_output.put_line('Stock Actual: '||rproducto.stock_actual);
        dbms_output.put_line(' ');
    end loop;
end;

/

exec sp_kardex;