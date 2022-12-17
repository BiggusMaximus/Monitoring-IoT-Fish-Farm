from flask import Blueprint, render_template, request, flash, redirect, url_for
import numpy as np

auth = Blueprint('auth', __name__)

@auth.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        print('request')
        username = request.form.get('username')
        password = request.form.get('password')
        if username == "homebase@homebase.com" and password == "homebase":
            print("able to login")
            return redirect(url_for('views.home'))
        else:
            if len(username) != 0:
                flash("Cant Login, wrong Account", category="error")
                print("gagagl")
    return render_template('login.html')

