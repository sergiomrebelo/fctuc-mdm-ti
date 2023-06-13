/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 9
 * Deep Vision Face detector ML
 *
 * @authors: Florian Bruggisser, Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   04–05–2023
 * @based:   based FaceDetector Example from DeepVision
 */
 
import ch.bildspur.vision.*;
import ch.bildspur.vision.result.*;


PImage testImage;

DeepVision vision = new DeepVision(this);
ULFGFaceDetectionNetwork network;
ResultList<ObjectDetectionResult> detections;

public void setup() {
  size(640, 480);
  colorMode(HSB, 360, 100, 100);

  testImage = loadImage(sketchPath("data/office.jpg"));

  println("creating network...");
  network = vision.createULFGFaceDetectorRFB320();

  println("loading model...");
  network.setup();

  //network.setConfidenceThreshold(0.2f);

  println("inferencing...");
  detections = network.run(testImage);
  println("done!");

  for (ObjectDetectionResult detection : detections) {
    System.out.println(detection.getClassName() + "\t[" + detection.getConfidence() + "]");
  }

  println("found " + detections.size() + " faces!");
}

public void draw() {
  background(55);

  detections = network.run(testImage);
  image(testImage, 0, 0);

  noFill();
  strokeWeight(2f);

  stroke(200, 80, 100);
  for (ObjectDetectionResult detection : detections) {
    rect(detection.getX(), detection.getY(), detection.getWidth(), detection.getHeight());
  }

  surface.setTitle("Face Recognition Test - FPS: " + Math.round(frameRate));
}
