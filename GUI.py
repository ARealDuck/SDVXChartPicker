import pysimplegui as sg
import os, sys
import json


# Set the settings for the GUI
settingsfile = 'settings.json'
languagefile = 'languages/language.json'
# This is needed to enforce the keys to be set properly from the language file, If disabled the keys stop working completely.
sg.set_options(suppress_key_guessing=True,)

class uifunc:
    def __init__(self):
        self.gui_mode = gui_mode.init
        self.detect_mode = detect_mode.init
        self.window = False
        self.plays = 0
        self.load_settings()
        self.load_languagelist()
        self.load_guilanguage()
    def load_settings(self):
        with open(settingsfile, 'r') as a:
            self.settings = json.load(a)