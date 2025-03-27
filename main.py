import os
import cv2


from flask import Flask
from flask import (
    render_template,
    request
)
from werkzeug.utils import secure_filename

app = Flask(__name__)
upload_folder = os.path.join('static', 'imagens')
app.config['UPLOAD'] = upload_folder


@app.route("/", methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        file = request.files['img']
        filename = secure_filename(file.filename)
        file.save(os.path.join(app.config['UPLOAD'], filename))
        img = os.path.join(app.config['UPLOAD'], filename)
        if request.form.get('greyscale'):

        return render_template('index.html', img=img)
    return render_template('index.html')


def home():
    return render_template('index.html')


if __name__ == '__main__':
    app.run(debug=True)
