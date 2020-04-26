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
    setMouseTracking(true);
    QPolygon test;
}
void Canvas::mousePressEvent(QMouseEvent *ev){
    lastMousePos = ev->pos();
    if (ev->button() == Qt::LeftButton){
        qDebug() << "My cpp function" << ev->x() << ev->y();
        qDebug() << "Shape index is" << shapeIndex;



        if(shapeIndex == 3 && !drawing){
            pointList = new int[polyPoints*2];
            pointIndex = 0;
            pointList[0] = currentMousePos.x();
            pointList[1] = currentMousePos.y();
            qDebug() << "placed first point";
            pointIndex+=2;
            drawing = true;

        }

        else if(shapeIndex == 3 && drawing){
            pointList[pointIndex] = currentMousePos.x();
            pointList[pointIndex + 1] = currentMousePos.y();
            qDebug() << "placed point at index" << pointIndex;
            //            currentPolygon.setPoint(0,100,200);
            //            currentPolygon.setPoint(1,currentMousePos);
            pointIndex+=2;
            if(pointIndex >= polyPoints*2){
                currentImage.currentPolygon.shape.putPoints(0,polyPoints,pointList);
                drawing = false;
                currentImage.polygonList.append(currentImage.currentPolygon);
            }

        }

        else if(shapeIndex == 4 && !drawing){
                   for(int i = 0; i < currentImage.polygonList.size(); i++){
                       QRect bounds = currentImage.polygonList[i].shape.boundingRect();
                       if(bounds.contains(lastMousePos)){
                           currentImage.dummyPolygon = currentImage.polygonList[i].shape;
                           moveIndex = i;
                           moving = true;


                       }
                   }
               }
               else if (shapeIndex == 5 && !drawing){
                   //for each shape, if within Xpx of a point then select point
                   for(int j = 0; j < currentImage.polygonList.size(); j++){
                       for(int k = 0; k <= currentImage.polygonList[j].shape.size(); k++){
                           QRect toleranceRect = QRect(currentImage.polygonList[j].shape[k].x() - pointSelectionTolerance/2,currentImage.polygonList[j].shape[k].y() - pointSelectionTolerance/2,pointSelectionTolerance,pointSelectionTolerance);
                           if(toleranceRect.contains(lastMousePos)){
                               //start moving point
                               currentImage.currentPolygon = currentImage.polygonList[j];
                               moveIndex = j;
                               pointMoveIndex = k;
                               moving = true;
       }
                       }
                   }
               }
               //if copy shape
               else if (shapeIndex == 6 && !drawing){
                   for (int l = 0; l < currentImage.polygonList.size(); l++) {
                       QRect bounds = currentImage.polygonList[l].shape.boundingRect();
                       if(bounds.contains(lastMousePos)){
                           clipboardPolygon = currentImage.polygonList[l].shape;

                       }
                   }
               }

        // start drawing if normal shape selected
        if(shapeIndex >= 0 && shapeIndex <= 2){
            drawing = true;
        }
        update();
    }
    //delete polygon
    if (ev->button() == Qt::RightButton && shapeIndex == 4){
           for(int i = 0; i < currentImage.polygonList.size(); i++){
               QRect bounds = currentImage.polygonList[i].shape.boundingRect();
               if(bounds.contains(lastMousePos)){
                   currentImage.polygonList.removeAt(i);
                   qDebug() << "deletingpolygon" ;
               }

           }


       }
       //paste polygon
       else if (ev->button() == Qt::RightButton && shapeIndex == 6){
           Shapes pastedPoly;
           pastedPoly.shape = clipboardPolygon.translated(lastMousePos - clipboardPolygon[0]);
           currentImage.polygonList.append((pastedPoly));
       }
   }


void Canvas::mouseMoveEvent(QMouseEvent *ev){
    currentMousePos = ev->pos();
    //move polygon with cursor movements
    if(moving && shapeIndex == 4){


        currentImage.currentPolygon.shape = currentImage.dummyPolygon.translated(currentMousePos-lastMousePos);
        currentImage.polygonList[moveIndex] = currentImage.currentPolygon;
        qDebug() << "currently moving polygon" ;
    }
    //move point to match cursor location
    else if(moving && shapeIndex == 5){

        currentImage.currentPolygon.shape[pointMoveIndex] = currentMousePos;
        qDebug() << "moving Point";
    }
    //if not moving or drawing, see if hoving over shape
    if(!moving && !drawing){

        for(int i = 0; i < currentImage.polygonList.size(); i++){
            QRect bounds = currentImage.polygonList[i].shape.boundingRect();
            if(bounds.contains(currentMousePos)){
                currentImage.currentPolygon = currentImage.polygonList[i];
                hovering = true;
                break;
            }
            hovering= false;

        }
    }
    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *ev){
    currentImage.currentPolygon.className = currentClass;
    if(drawing && shapeIndex != 3){
        drawing = false;
        currentImage.polygonList.append(currentImage.currentPolygon);
        qDebug() << "shape list has " << currentImage.polygonList.size();
    }
    if (moving && shapeIndex == 4){
        moving = false;
        qDebug() << "stopped moving polygon" ;
    }
    else if (moving && shapeIndex == 5){
        moving = false;
        currentImage.polygonList[moveIndex] = currentImage.currentPolygon;
    }

    update();
}




void Canvas::paintEvent(QPaintEvent *ev){
    QPainter painter;
    painter.begin(this);

    //paint image;
    if(!currentImage.image.isNull())
    {
        painter.drawImage(0,0,currentImage.image);
    }

    //paint existing polygons
    if(!currentImage.polygonList.isEmpty()){
        for(Shapes polygon: currentImage.polygonList){
            painter.drawPolygon(polygon.shape);

        }
    }



    if(shapeIndex == 0){

        currentImage.currentPolygon.shape.setPoints(4,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),lastMousePos.x(),currentMousePos.y());
        currentImage.currentPolygon.shapeName = "Rectangle";

    }

    else if(shapeIndex == 1){
        trapDist = trapeziumDistanceConstant+abs((currentMousePos.x() - lastMousePos.x())/4);
        //first vertex is where the mouse was clicked
        QPoint* v2 = new QPoint(currentMousePos.x() - trapDist,lastMousePos.y());
        QPoint* v3 = new QPoint(lastMousePos.x() - trapDist,currentMousePos.y());
        //last vertex where mouse is currently

        //set points of trapezium
        currentImage.currentPolygon.shape.setPoints(4,lastMousePos.x(),lastMousePos.y(),v2->x(),v2->y(),currentMousePos.x(),currentMousePos.y(),v3->x(),v3->y());
        currentImage.currentPolygon.shapeName ="Trapezium";
       // painter.drawPolygon(currentImage.currentPolygon);
    }

    else if(shapeIndex == 2){
        QPoint* tv2 =new QPoint(lastMousePos.x() ,currentMousePos.y());
        currentImage.currentPolygon.shape.setPoints(3,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),tv2->x(),tv2->y());
        currentImage.currentPolygon.shapeName = "Triangle";
        qDebug() << "v2 is" << tv2->x() << tv2->y();
        //painter.drawPolygon(currentImage.currentPolygon);
    }


    if(drawing || moving){
        painter.drawPolygon(currentImage.currentPolygon.shape);
    }

        //display class name
    if(hovering){
        painter.drawText(currentMousePos,currentImage.currentPolygon.className);
    }

    painter.end();
}

void Canvas::setCurrentClass(QString name){
        //replace current class with arugment
    currentClass = name;
}
