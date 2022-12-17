from flask import Blueprint, render_template, Response,jsonify
import cv2
import numpy as np

views = Blueprint('views', __name__)

def play_sound():
    

def gen_frames():
    global camera
    camera = cv2.VideoCapture(0)
    global video_camera
    while True:
        success, frame = camera.read()  # read the camera frame
        if not success:
            break
        else:
            ret, buffer = cv2.imencode('.jpg', frame)
            frame = buffer.tobytes()
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')  # concat frame one by one and show result
                   

@views.route('home')
def home():
    return render_template('home.html')


@views.route('/streaming', endpoint='stream')
def video_feed():
    print('a')
    return Response(gen_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@views.route('/update', methods=["GET"])
def update():
    print('kontol')
    ph = np.random.rand()
    tds = np.random.rand()
    temp = np.random.rand()
    data = [{
        "ph": ph,
        "tds": tds,
        "temp": temp
    }]
    print(jsonify(data))
    return jsonify(data)
