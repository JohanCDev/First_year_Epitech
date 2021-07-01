import { StatusBar } from 'expo-status-bar';
import React, { Component } from 'react'
import { Text, TextInput, View, TouchableOpacity } from 'react-native';
import { back, texts, buttons } from './styles'

import firebase from 'firebase'

const Line = () => {
    return (
        <View
            style={{
                paddingTop: 20,
                alignSelf: 'center',
                borderBottomColor: '#5A5A5A',
                width: 390,
                borderBottomWidth: 1,
            }}
        />
    )
}

class MyConnexion extends Component {
    constructor(props) {
        super(props);

        this.state = {
            email: '',
            password: '',
        }

        this.onSignUp = this.onSignUp.bind(this)
    }

    onSignUp() {
        const { email, password } = this.state;
        firebase.auth().signInWithEmailAndPassword(email, password)
            .then((result) => {
                this.props.navigation.navigate('Home')
                console.log(result)
            })
            .catch((error) => {
                console.log(error)
            })
    }

    render() {
        return (
            <View style={back.inscription_container}>
                <Text style={texts.inscription}>Garrasi</Text>
                <TextInput
                    autoCorrect={false}
                    placeholderTextColor={"#BBBBBB"}
                    style={texts.enter_text}
                    placeholder="E-mail"
                    keyboardType='email-address'
                    onChangeText={(email) => this.setState({ email })}
                    returnKeyType={'done'}
                />
                <TextInput
                    secureTextEntry={true}
                    autoCorrect={false}
                    placeholderTextColor={"#BBBBBB"}
                    style={texts.enter_text}
                    placeholder="Mot de passe"
                    onChangeText={(password) => this.setState({ password })}
                    returnKeyType={'done'}
                />
                <TouchableOpacity
                    style={buttons.forgot_password}
                    onPress={console.log("Forgot password")}>
                    <Text style={texts.forgot_password}>Mot de passe oublié ?</Text>
                </TouchableOpacity>
                <TouchableOpacity
                    style={buttons.connexion}
                    onPress={() => this.onSignUp()}>
                    <Text style={texts.connexion}>Connexion</Text>
                </TouchableOpacity>
                <Line />
                <TouchableOpacity onPress={() => this.props.navigation.navigate('register')}>
                    <Text style={texts.pas_inscrit}>Pas encore inscrit ?</Text>
                </TouchableOpacity>
                <StatusBar style="auto" />
            </View>
        );
    }
}

export default MyConnexion