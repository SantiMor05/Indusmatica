--p1
set SERVEROUTPUT on;
/
CREATE or replace PROCEDURE sp_ventas_rango
(p_fecha_ini date,p_fecha_fin date)
as
  cursor c_cabecera is
  select v.venta_id,cli.nombre,v.fecha_venta
  from l6_ventas v,l6_clientes cli
  where v.fecha_venta between p_fecha_ini and p_fecha_fin and
  cli.cliente_id=v.cliente_id;
  
  cursor c_detalle(p_venta number) is
  select pro.nombre,vd.cantidad,vd.precio_unitario,vd.precio_final
  from l6_ventas_detalle vd,l6_productos pro
  where p_venta=vd.venta_id and vd.producto_id=pro.producto_id;
  
BEGIN
    for r_cabecera in c_cabecera loop
        dbms_output.put_line('Documento de venta: '||r_cabecera.venta_id);
        dbms_output.put_line('Cliente: '||r_cabecera.nombre);
        dbms_output.put_line('Fecha: '||r_cabecera.fecha_venta);
        dbms_output.put_line(rpad('Nombre',25,' ')||(' Cantidad  Precio Unit.  ')||
        'Precio Final');
        for r_detalle in c_detalle(r_cabecera.venta_id) loop
            dbms_output.put_line(rpad(r_detalle.nombre,25,' ')||'  '||
            rpad(r_detalle.cantidad,8,' ')||'  '||
            rpad(r_detalle.precio_unitario,12,' ')||'  '||
            r_detalle.precio_final);                
        end loop;
    end loop;
  
  
END;
/    

exec sp_ventas_rango('01/01/2024','30/01/2024');
/
--p2
CREATE or replace PROCEDURE sp_campanias
IS
  cursor c_cabecera is
  select campania_id,nombre
  from l6_campanias;
  
  cursor c_detalle(p_campania_id number) is
  select cli.nombre,cli.apellido
  from l6_ventas_detalle vd,l6_ventas v,l6_clientes cli
  where vd.campania_id=p_campania_id and vd.venta_id=v.venta_id and
  v.cliente_id=cli.cliente_id
  group by cli.nombre,cli.apellido;
  
   --ventas que hicieron con al menos un detalle de venta con compania null
  cursor c_clientes_busc is
  select max(cli.nombre||' '||cli.apellido) as nombre
  from l6_ventas_detalle vd,l6_ventas v,l6_clientes cli
  where v.venta_id=vd.venta_id and cli.cliente_id=v.cliente_id
  and vd.campania_id is null
  group by cli.nombre||' '||cli.apellido;
  
  
BEGIN
  for r_cabecera in c_cabecera loop
    dbms_output.put_line('Nombre de Campania: '||r_cabecera.nombre);
    dbms_output.put_line('---------------------------------------------------');
   
    for r_detalle in c_detalle(r_cabecera.campania_id) loop
        dbms_output.put(r_detalle.nombre||' ');
        dbms_output.put_line(r_detalle.apellido);
    end loop;
    
    dbms_output.put_line('Nombre de Campania: Sin campaña');
    dbms_output.put_line('---------------------------------------------------');    
    for r_cliente in c_clientes_busc loop
        dbms_output.put_line(r_cliente.nombre);
    end loop;    
        
  end loop;
END;
/
exec sp_campanias;
/
--p3
CREATE or replace PROCEDURE sp_reporte_produc
IS
  cursor c_productos is
  
  select p.codigo_producto as codigo,p.nombre,
  e.nombre as editorial,l.isbn,l.anio_publicacion as anio,
  l.libro_id
  from l6_productos p,l6_editoriales e,l6_libros l
  where p.editorial_id=e.editorial_id and
  p.producto_id=l.producto_id
  
  union all
  
  select p.codigo_producto as codigo,p.nombre,
  e.nombre as editorial,null,null,null
  from l6_productos p,l6_editoriales e
  where p.editorial_id=e.editorial_id and 
  p.producto_id not in (select producto_id from l6_libros )
  
  union all
  
  select p.codigo_producto as codigo,p.nombre,
  null,null,null,null
  from l6_productos p
  where p.editorial_id is null and
  p.producto_id not in (select producto_id from l6_libros)
  
  order by 1;
  
  cursor c_cursos(p_libro number) is
  select cur.codigo,cur.nombre
  from l6_bibliografia_cursos bcur,l6_cursos cur
  where bcur.libro_id=p_libro and bcur.curso_id=cur.curso_id;
  
BEGIN
    for r_producto in c_productos loop
        dbms_output.put_line('Codigo del producto: '||
        r_producto.codigo);
        dbms_output.put_line('Nombre del producto: '||
        r_producto.nombre);
        
        if r_producto.editorial is not null then
            dbms_output.put_line('------------------------------------');
            dbms_output.put_line('Editoral: '||r_producto.editorial);
        end if;    
        if r_producto.isbn is not null then
            dbms_output.put_line('ISBN: '||r_producto.isbn);
            dbms_output.put_line('Anho: '||r_producto.anio);
        end if;
        
        if r_producto.libro_id is not null then
            dbms_output.put_line('------------------------------------');
        end if;

        for r_curso in c_cursos(r_producto.libro_id) loop
            dbms_output.put_line(r_curso.codigo||' '||r_curso.nombre);
        end loop;
        dbms_output.put_line(' ');
        dbms_output.put_line(' ');
    end loop;
END;
/
exec sp_reporte_produc;
/
--p4
CREATE or replace PROCEDURE sp_kardex
IS
    cursor c_productos is
    select *
    from l6_productos;
    
    cursor c_movimientos(p_producto number) is
    
    select v.fecha_venta as fecha,vd.cantidad,'Venta' as motivo
    from l6_ventas_detalle vd,l6_ventas v
    where vd.producto_id=p_producto and vd.venta_id=v.venta_id
    
    union all
    
    select fecha_registro,cantidad,motivo
    from l6_perdidas_inventario
    where producto_id=p_producto
    
    order by 1;
    
    v_salidas number;
    
BEGIN
    for r_producto in c_productos loop
        dbms_output.put_line('Codigo del Producto: '||
        r_producto.codigo_producto);
        dbms_output.put_line('Nombre del Producto: '||
        r_producto.nombre);
        
        v_salidas:=0;
        for r_mov in c_movimientos(r_producto.producto_id) loop
            v_salidas:=v_salidas+r_mov.cantidad;
        end loop;
        
        dbms_output.put_line('Stock inicial: '||
        (r_producto.stock_actual+v_salidas));
        dbms_output.put_line(rpad('-',60,'-'));
        dbms_output.put_line('Movimientos');
        dbms_output.put_line(rpad('Fecha',8,' ')||'  Cantidad'
        ||'  Motivo');
        
        for r_mov in c_movimientos(r_producto.producto_id) loop
            dbms_output.put_line(r_mov.fecha||'  '||
            rpad(r_mov.cantidad,8,' ')||'  '||r_mov.motivo);
        end loop;
        dbms_output.put_line(' ');
        
        dbms_output.put_line(rpad('-',60,'-'));
        dbms_output.put_line('Stock Actual: '||
        r_producto.stock_actual);
        dbms_output.put_line(' ');
    end loop;
  
  
END;
/
exec sp_kardex;




      