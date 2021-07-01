import { StatusBar } from 'expo-status-bar';
import React, { Component } from 'react'
import { Text, TextInput, View, TouchableOpacity, Keyboard } from 'react-native';
import { back, texts, buttons } from '../styles'

import firebase from 'firebase'
import "firebase/firestore"

export class register extends Component {
    constructor(props) {
        super(props);

        this.state = {
            email: '',
            password: '',
            name: ''
        }

        this.onSignUp = this.onSignUp.bind(this)
    }

    onSignUp() {
        const { email, password, name } = this.state;
        firebase.auth().createUserWithEmailAndPassword(email, password).then((result) => {
            firebase.firestore().collection("users")
                .doc(firebase.auth().currentUser.uid)
                .set({
                    name,
                    email
                })
            firebase.auth().currentUser.updateProfile({
                displayName: name,
                photoURL: "https://www.winhelponline.com/blog/wp-content/uploads/2017/12/user.png"
            }).then(() => {
                console.log(firebase.auth().currentUser)
            }).catch((error) => {
                console.log("Error when updating displayName")
            });
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
                    placeholder="Nom d'utilisateur"
                    onChangeText={(name) => this.setState({ name })}
                    returnKeyType={'done'}
                />
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
                    style={buttons.connexion}
                    onPress={() => this.onSignUp()}>
                    <Text style={texts.connexion}>Créer un compte</Text>
                </TouchableOpacity>
                <StatusBar style="auto" />
            </View>
        )
    }
}

export default register