#include"canvas.h"

//Canvas::Canvas(QLabel *parent)
//    : QLabel(parent)
//{
//    setAttribute(Qt::WA_StaticContents);
//}
Canvas::Canvas(QWidget *parent)
    : QLabel(parent)
{
    setAttribute(Qt::WA_StaticContents);

    QPolygon test;
//    test.setPoints(2,100,100,300,300);
//    polygonList.append(test);
}

void Canvas::mousePressEvent(QMouseEvent *ev){
    if (ev->button() == Qt::LeftButton){
        qDebug() << "My cpp function" << ev->x() << ev->y();
        qDebug() << "Shape index is" << shapeIndex;
        lastMousePos = ev->pos();

        if(shapeIndex!= 100){
            drawing = true;
        }
        //update();

    }
}

void Canvas::mouseMoveEvent(QMouseEvent *ev){
    if(drawing){
        currentMousePos = ev->pos();
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *ev){
    if(drawing){
        drawing = false;
        polygonList.append(currentPolygon);
    }
}


void Canvas::paintPolygon(QPolygon polygon){
    QPainter painter;
    painter.drawPolygon(polygon);
}

void Canvas::paintEvent(QPaintEvent *ev){
    QPainter painter;
    painter.begin(this);

    //paint image;
    if(!image.isNull())
    {
        painter.drawImage(0,0,image);
    }

    //paint existing polygons
    if(!polygonList.isEmpty()){
        for(QPolygon polygon: polygonList){
            painter.drawPolygon(polygon);

        }
    }



    if(shapeIndex == 0){

        currentPolygon.setPoints(4,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),lastMousePos.x(),currentMousePos.y());
        painter.drawPolygon(currentPolygon);

    }

    else if(shapeIndex == 1){
        trapDist = trapeziumDistanceConstant+abs((currentMousePos.x() - lastMousePos.x())/4);
        //first vertex is where the mouse was clicked
        QPoint* v2 = new QPoint(currentMousePos.x() - trapDist,lastMousePos.y());
        QPoint* v3 = new QPoint(lastMousePos.x() - trapDist,currentMousePos.y());
        //last vertex where mouse is currently

        //set points of trapezium
        currentPolygon.setPoints(4,lastMousePos.x(),lastMousePos.y(),v2->x(),v2->y(),currentMousePos.x(),currentMousePos.y(),v3->x(),v3->y());
        painter.drawPolygon(currentPolygon);
    }

    else if(shapeIndex == 2){
        QPoint* tv2 =new QPoint(lastMousePos.x() ,currentMousePos.y());
        currentPolygon.setPoints(3,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),tv2->x(),tv2->y());
        qDebug() << "v2 is" << tv2->x() << tv2->y();
        painter.drawPolygon(currentPolygon);
    }

    painter.end();
}
