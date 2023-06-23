import socket
import threading
import re
from command_response_actions_dict import *

class Client:
    def __init__(self, port, team, machine):
        self.port = port
        self.team = team
        self.machine = machine
        self.sock = None
        self.level = 1
        self.missing = []
        self.cmd_buff = []
        self.direction = []
        self.direction_index = 0
        self.reposition = []
        self.reposition_index = 0
        self.ready = 0
        self.team_items = init_team_items()

    def connect_to_server(self):
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            server_address = (self.machine, self.port)
            self.sock.connect(server_address)
            print(f"Connected to server {self.machine} on port {self.port}")
        except Exception as e:
            print(f"Error connecting to server: {str(e)}")
            exit(84)

            sock.connect(server_address)
            print(f"connected to server {self.machine} on port {self.port}")
        except:
            print("Can't connect to server. Please try again later.\n")
    
    def get_response_continuously(self):
        try:
            response = self.receive_server_response()
            print(f"Got a continuous response : {response}")
            self.check_response(response)
        except Exception as e:
            print(f"Error receiving response: {str(e)}")
    
    def check_response(self, response: str) -> int:
        for cmd in self.cmd_buff:
            if re.match(response_dict[cmd], response):
                action_dict[cmd](self, response)
                return 1
        for stray in stray_response_dict:
            if re.match(stray_response_dict[stray], response):
                action_dict[stray](self, response)
                return 2
        return 0

    def write_response_to_socket(self, response: str):
        try:
            self.sock.send(response.encode())
        except Exception as e:
            print(f"Error sending response: {str(e)}")
            exit(84)

def init_team_items():
    team_items = {}
    team_items["linemate"] = 0
    team_items["deraumere"] = 0
    team_items["sibur"] = 0
    team_items["mendiane"] = 0
    team_items["phiras"] = 0
    team_items["thystame"] = 0
    return team_items