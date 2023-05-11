/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 9
 * Nueral Style Transfer example
 *
 * @authors: Sérgio M. Rebelo, Florian Bruggisser, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   04–05–2023
 * @based:   based FaceDetector Example from DeepVision
 */


import ch.bildspur.vision.*;
import ch.bildspur.vision.result.*;
import ch.bildspur.vision.dependency.*;

PImage groundTruth;

DeepVision vision = new DeepVision(this);
StyleTransferNetwork network;
ImageResult result;

Dependency model = Repository.InstanceNormMosaic;

void setup() {
  size(1280, 428);

  groundTruth = loadImage(sketchPath("data/office.jpg"));


  loadModel();
}

public void draw() {
  background(55);
  image(groundTruth, 0, 0);
  image(result.getImage(), 640, 0);
  surface.setTitle("Style Transfer - FPS: " + Math.round(frameRate));
}

void keyPressed () {
  println (key);
  char k = Character.toUpperCase(key);
  boolean n = true;
  switch (k) {
  case '1':
    model = Repository.InstanceNormMosaic;
    break;
  case '2':
    model = Repository.InstanceNormLaMuse;
    break;
  case '3':
    model = Repository.InstanceNormMosaic;
    break;
  case '4':
    model = Repository.InstanceNormCandy;
    break;
  case '5':
    model = Repository.InstanceNormTheScream;
    break;
  case '6':
    model = Repository.InstanceNormUdnie;
    break;
  default:
    n = false;
    break;
  }

  if (n) {
    loadModel();
  }
}

void loadModel () {
  network = vision.createStyleTransfer(model);
  network.setup();
  result = network.run(groundTruth);
}
