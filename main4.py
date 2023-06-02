from cvzone.ClassificationModule import Classifier
import cv2
import serial

d = serial.Serial('com18', 9600)
cap = cv2.VideoCapture(1)
Classifier = Classifier('keras_model.h5', 'labels.txt')
string=""
while True:

    success, img = cap.read()

    prediction = Classifier.getPrediction(img)
    if prediction[1] ==0:
        string = "00001"
    if prediction[1] == 1:
        string = "10000"
    if prediction[1] == 2:
        string = "01000"
    if prediction[1] == 3:
        string = "00100"
    if prediction[1] == 4:
        string = "00010"
    print(string)
    if prediction:

        string = string + '\r'
        print(string)
        print(string.encode())
        d.write(string.encode())

    cv2.imshow("Image", img)
    if cv2.waitKey(3000) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()