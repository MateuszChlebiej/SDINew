#include"canvas.h"


Canvas::Canvas(QWidget *parent)
    : QLabel(parent)
{
    setAttribute(Qt::WA_StaticContents);

    QPolygon test;
<<<<<<< Updated upstream
//    test.setPoints(2,100,100,300,300);
//    polygonList.append(test);
=======

>>>>>>> Stashed changes
}

void Canvas::mousePressEvent(QMouseEvent *ev){
    if (ev->button() == Qt::LeftButton){
        qDebug() << "My cpp function" << ev->x() << ev->y();
        qDebug() << "Shape index is" << shapeIndex;
        lastMousePos = ev->pos();

        //if drawing first point of custom polygon
        if(shapeIndex == 3 && !drawing){
            pointList = new int[polyPoints*2];
            pointIndex = 0;
            pointList[0] = lastMousePos.x();
            pointList[1] = lastMousePos.y();
            qDebug() << "placed first point";
            pointIndex+= 2;
            drawing = true;

        }
<<<<<<< Updated upstream
=======
        //if drawing next points of custom polygon
>>>>>>> Stashed changes
        else if(shapeIndex == 3 && drawing){
            pointList[pointIndex] = lastMousePos.x();
            pointList[pointIndex + 1] = lastMousePos.y();
            qDebug() << "placed point at index" << pointIndex;
<<<<<<< Updated upstream
//            currentPolygon.setPoint(0,100,200);
//            currentPolygon.setPoint(1,currentMousePos);
            pointIndex++;
            if(pointIndex == polyPoints + 1){
                currentPolygon.putPoints(0,polyPoints,pointList);
=======

            pointIndex+= 2;
            //if all points fill in, close shape
            if(pointIndex >= 2*polyPoints){
                currentImage.currentPolygon.shape.putPoints(0,polyPoints,pointList);
>>>>>>> Stashed changes
                drawing = false;
                polygonList.append(currentPolygon);
            }

        }
<<<<<<< Updated upstream
        //update();
=======
        //if move selected, start moving shape if cursor within shape bounds
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
>>>>>>> Stashed changes
        if(shapeIndex >= 0 && shapeIndex <= 2){
            drawing = true;
        }
        update();
    }
<<<<<<< Updated upstream
}

void Canvas::mouseMoveEvent(QMouseEvent *ev){
    if(drawing){
        currentMousePos = ev->pos();
        update();
=======
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
>>>>>>> Stashed changes
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *ev){
<<<<<<< Updated upstream
    if(drawing && shapeIndex != 3){
        drawing = false;
        polygonList.append(currentPolygon);
=======
    currentImage.currentPolygon.className = currentClass;
    //append normal polygon
    if(drawing && shapeIndex != 3){
        drawing = false;
        currentImage.polygonList.append(currentImage.currentPolygon);
        qDebug() << "shape list has " << currentImage.polygonList.size();
    }
    // stop moving polygon
    if (moving && shapeIndex == 4){
        moving = false;
        qDebug() << "stopped moving polygon" ;
    }
    // stop moving point
    else if (moving && shapeIndex == 5){
        moving = false;
        currentImage.polygonList[moveIndex] = currentImage.currentPolygon;
>>>>>>> Stashed changes
    }
    update();
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


    //paint current shape
    if(shapeIndex == 0){

<<<<<<< Updated upstream
        currentPolygon.setPoints(4,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),lastMousePos.x(),currentMousePos.y());
        painter.drawPolygon(currentPolygon);
=======
        currentImage.currentPolygon.shape.setPoints(4,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),lastMousePos.x(),currentMousePos.y());

>>>>>>> Stashed changes

    }

    else if(shapeIndex == 1){
        trapDist = trapeziumDistanceConstant+abs((currentMousePos.x() - lastMousePos.x())/4);

        QPoint* v2 = new QPoint(currentMousePos.x() - trapDist,lastMousePos.y());
        QPoint* v3 = new QPoint(lastMousePos.x() - trapDist,currentMousePos.y());

<<<<<<< Updated upstream
        //set points of trapezium
        currentPolygon.setPoints(4,lastMousePos.x(),lastMousePos.y(),v2->x(),v2->y(),currentMousePos.x(),currentMousePos.y(),v3->x(),v3->y());
        painter.drawPolygon(currentPolygon);
=======
        currentImage.currentPolygon.shape.setPoints(4,lastMousePos.x(),lastMousePos.y(),v2->x(),v2->y(),currentMousePos.x(),currentMousePos.y(),v3->x(),v3->y());

>>>>>>> Stashed changes
    }

    else if(shapeIndex == 2){
        QPoint* tv2 =new QPoint(lastMousePos.x() ,currentMousePos.y());
        currentPolygon.setPoints(3,lastMousePos.x(),lastMousePos.y(),currentMousePos.x(),currentMousePos.y(),tv2->x(),tv2->y());
        qDebug() << "v2 is" << tv2->x() << tv2->y();
<<<<<<< Updated upstream
        painter.drawPolygon(currentPolygon);
    }

    else if(shapeIndex == 3){
        int initalisedPoints = 0;
        for(int i = 0; i < polyPoints ; i++){
            //if(!pointList[i].isNull()){initalisedPoints++;}

        }
        for(int j = 0; j< initalisedPoints ; j++){


        }
//        currentPolygon.setPoint(0,200,200);
//        currentPolygon.setPoint(1,300,300);
//        currentPolygon.setPoint(0,400,200);
//        currentPolygon.setPoints(3,200,200,300,300,400,200);
        painter.drawPolygon(currentPolygon);
=======

    }

    //display current polygon if moving
    if(drawing || moving){
        painter.drawPolygon(currentImage.currentPolygon.shape);
    }

    //if hovering display class name
    if(hovering){
        painter.drawText(currentMousePos,currentImage.currentPolygon.className);
>>>>>>> Stashed changes
    }

    painter.end();
}

<<<<<<< Updated upstream
QList<QPoint> Canvas::getPoints(int numVertecies, int listIndex){
    QList<QPoint> pointList;
    for(int i = 0; i < numVertecies; i++){
        pointList.append(polygonList[listIndex].point(i));

    }
    return pointList;
=======
void Canvas::setCurrentClass(QString name){
    //replace current class with arugment
    currentClass = name;
>>>>>>> Stashed changes
}
