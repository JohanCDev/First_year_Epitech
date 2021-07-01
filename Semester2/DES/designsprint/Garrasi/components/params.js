import { StatusBar } from 'expo-status-bar';
import React, { Image, Component } from 'react';
import { Text, TextInput, View, TouchableHighlight, ScrollView, FlatList, TouchableOpacity } from 'react-native';
import { back, texts, buttons, views, images, home, add_post, params } from './styles'
import { description_space, info_list, reaction_bar } from './styles_flatlist'
import Icon from 'react-native-vector-icons/FontAwesome'
import Icon_Data from 'react-native-vector-icons/Entypo'
import Icon_Time from 'react-native-vector-icons/MaterialIcons'
import Icon_Shield from 'react-native-vector-icons/MaterialCommunityIcons'
import Icon_Help from 'react-native-vector-icons/AntDesign'
import firebase from 'firebase'
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';

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

export default class MyParams extends React.Component {
    render() {
        return (
            <View style={{ flex: 1 }}>
                <View style={add_post.top_bar}>
                    <View style={{ flex: 2 }}></View>
                    <View style={{ flex: 3 }}>
                        <Text style={params.title}>Paramètres</Text>
                    </View>
                    <View style={{ flex: 2, alignItems: 'center' }}>
                    </View>
                </View>
                <View style={add_post.container}>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Time style={{ paddingLeft: 10, paddingTop: 2 }} name="access-time" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Votre activité</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Data style={{ paddingLeft: 10, paddingTop: 2 }} name="database" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Vos données</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon style={{ paddingLeft: 10, paddingTop: 2 }} name="bell-o" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Notifications</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Shield style={{ paddingLeft: 10, paddingTop: 2 }} name="shield-check" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Sécurité</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Shield style={{ paddingLeft: 10, paddingTop: 2 }} name="credit-card" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Paiements</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Time style={{ paddingLeft: 10, paddingTop: 2 }} name="accessibility" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Confidentialité</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Shield style={{ paddingLeft: 10, paddingTop: 2 }} name="shield-account-outline" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Compte</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Help style={{ paddingLeft: 10, paddingTop: 2 }} name="questioncircleo" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>Aide</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={params.buttons}>
                        <View style={{ flex: 1, flexDirection: 'row' }}>
                            <View style={{ flex: 1 }}>
                                <Icon_Help style={{ paddingLeft: 10, paddingTop: 2 }} name="infocirlceo" size={30} color="#5A5A5A" />
                            </View>
                            <View style={{ flex: 8, justifyContent: 'center' }}>
                                <Text style={params.text_in_buttons}>A propos</Text>
                            </View>
                        </View>
                    </TouchableOpacity>
                    <Line />
                    <Text style={params.footer}>Toute application ressemblant ou ayant ressemblée à celle ci ne serait que pure et fortuite coïncidence</Text>
                    <Line />
                    <TouchableOpacity onPress={() => {
                        try {
                            firebase.auth().signOut()
                            this.props.navigation.navigate('Connexion');
                        } catch (e) {
                            console.log(e)
                        }
                    }}>
                        <Text style={params.button_deconnect}>Se déconnecter</Text>
                    </TouchableOpacity>
                    <TouchableOpacity onPress={() => {
                        firebase.auth().currentUser.delete()
                        .then(() => {
                            console.log('delete successful')
                            this.props.navigation.navigate('Connexion')
                        }).catch((error) => {
                            console.log('An error occured when deleting the account')
                        })
                    }}>
                        <Text style={params.button_supp}>Supprimer mon compte</Text>
                    </TouchableOpacity>
                </View>
                <StatusBar style="auto" />
            </View>
        )
    }
}