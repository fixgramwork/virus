from flask import Flask, send_file

app = Flask(__name__)

@app.route('/download')
def download_file():
    file_path = "malware.exe"
    return send_file(file_path, as_attachment=True)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000, debug=True)