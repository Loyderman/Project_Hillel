import QtQuick
import QtQuick.Controls

Window
{
   id: mainWnd
   width: 640
   height: 480
   visible: true
   title: "Hello QML"




   Button{
      id: qmlButton
      text: "Click"
      width: 100
      height: 50
      x: 120
      y: 250

      anchors.centerIn: parent
      onClicked:
      {
         if(qmlButton.text === "Click" )
         {
            qmlButton.text = "Clicked"
         }
         else
            qmlButton.text = "Click"
      }



      onPressAndHold:
      {
         if(qmlButton.pressed())
         {
         qmlButton.text = "Holded"
         }
         else if(qmlButton.released())
         {
             qmlButton.text = "Released"
         }


      }







      onHoveredChanged:
      {
         if(qmlButton.text !== "howered")
             qmlButton.text = "howered"
         else

            qmlButton.text = "Click"
      }

      onHeightChanged:
      {

         if(qmlButton.text === "howered")
         {
            qmlButton.setHeight(100)
         }
         else
         {
            qmlButton.setHeight(50)
         }

      }
   }
}
